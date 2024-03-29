// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Solbit developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#if defined(HAVE_CONFIG_H)
#include "config/solbit-config.h"
#endif

#include "chainparams.h"
#include "clientversion.h"
#include "config.h"
#include "forks_csv.h"
#include "fs.h"
#include "httprpc.h"
#include "httpserver.h"
#include "init.h"
#include "noui.h"
#include "rpc/server.h"
#include "scheduler.h"
#include "unlimited.h"
#include "util.h"
#include "utilstrencodings.h"

#include <boost/algorithm/string/predicate.hpp>
#include <boost/thread.hpp>

#include <stdio.h>

/* Introduction text for doxygen: */

/*! \mainpage Developer documentation
 *
 * \section intro_sec Introduction
 *
 //www.solbit.org/),
 * This is the developer documentation of the reference client for an experimental new digital currency called Solbit
 (https:
 * which enables instant payments to anyone, anywhere in the world. Solbit uses peer-to-peer technology to operate
 * with no central authority: managing transactions and issuing money are carried out collectively by the network.
 *
 * The software is a community-driven open source project, released under the MIT license.
 *
 * \section Navigation
 * Use the buttons <code>Namespaces</code>, <code>Classes</code> or <code>Files</code> at the top of the page to start
 navigating the code.
 */

static bool fDaemon;

void WaitForShutdown(boost::thread_group *threadGroup)
{
    bool fShutdown = ShutdownRequested();
    // Tell the main threads to shutdown.
    while (!fShutdown)
    {
        MilliSleep(200);
        fShutdown = ShutdownRequested();
    }
    if (threadGroup)
    {
        Interrupt(*threadGroup);
        threadGroup->join_all();
    }
}

//////////////////////////////////////////////////////////////////////////////
//
// Start
//
bool AppInit(int argc, char *argv[])
{
    boost::thread_group threadGroup;
    CScheduler scheduler;

    auto &config = const_cast<Config &>(GetConfig());

    bool fRet = false;

    //
    // Parameters
    //
    // If Qt is used, parameters/solbit.conf are parsed in qt/solbit.cpp's main()
    AllowedArgs::Solbitd allowedArgs(&tweaks);
    try
    {
        ParseParameters(argc, argv, allowedArgs);
    }
    catch (const std::exception &e)
    {
        fprintf(stderr, "Error parsing program options: %s\n", e.what());
        return false;
    }

    // Process help and version before taking care about datadir
    if (mapArgs.count("-?") || mapArgs.count("-h") || mapArgs.count("-help") || mapArgs.count("-version"))
    {
        std::string strUsage =
            strprintf(_("%s Daemon"), _(PACKAGE_NAME)) + " " + _("version") + " " + FormatFullVersion() + "\n";

        if (mapArgs.count("-version"))
        {
            strUsage += FormatParagraph(LicenseInfo());
        }
        else
        {
            strUsage += "\n" + _("Usage:") + "\n" + "  solbitd [options]                     " +
                        strprintf(_("Start %s Daemon"), _(PACKAGE_NAME)) + "\n";

            strUsage += "\n" + allowedArgs.helpMessage();
        }

        fprintf(stdout, "%s", strUsage.c_str());
        return true;
    }

    // bip135 begin
    // dump default deployment info and exit, if requested
    if (GetBoolArg("-dumpforks", false))
    {
        std::stringstream ss;
        ss << "# " << strprintf(_("%s Daemon"), _(PACKAGE_NAME)) << " " << _("version") << " " << FormatFullVersion();
        ss << "\n" << FORKS_CSV_FILE_HEADER;
        ss << NetworkDeploymentInfoCSV(CBaseChainParams::MAIN);
        ss << NetworkDeploymentInfoCSV(CBaseChainParams::UNL);
        ss << NetworkDeploymentInfoCSV(CBaseChainParams::TESTNET);
        ss << NetworkDeploymentInfoCSV(CBaseChainParams::REGTEST);
        std::cout << ss.str();
        return true;
    }
    // bip135 end

    try
    {
        if (!fs::is_directory(GetDataDir(false)))
        {
            fprintf(stderr, "Error: Specified data directory \"%s\" does not exist.\n", mapArgs["-datadir"].c_str());
            return false;
        }
        try
        {
            ReadConfigFile(mapArgs, mapMultiArgs, allowedArgs);
        }
        catch (const std::exception &e)
        {
            fprintf(stderr, "Error reading configuration file: %s\n", e.what());
            return false;
        }
        // Check for -testnet or -regtest parameter (Params() calls are only valid after this clause)
        try
        {
            SelectParams(ChainNameFromCommandLine());
        }
        catch (const std::exception &e)
        {
            fprintf(stderr, "Error: %s\n", e.what());
            return false;
        }

        // Command-line RPC
        bool fCommandLine = false;
        for (int i = 1; i < argc; i++)
        {
            if (!IsSwitchChar(argv[i][0]) && !boost::algorithm::istarts_with(argv[i], "solbit:") &&
                !boost::algorithm::istarts_with(argv[i], "solbitcash:"))
            {
                fCommandLine = true;
                break;
            }
        }

        if (fCommandLine)
        {
            fprintf(stderr, "Error: There is no RPC client functionality in solbitd anymore. Use the solbit-cli "
                            "utility instead.\n");
            return false;
        }
#ifndef WIN32
        fDaemon = GetBoolArg("-daemon", false);
        if (fDaemon)
        {
            fprintf(stdout, "Solbit server starting\n");

            // Daemonize
            pid_t pid = fork();
            if (pid < 0)
            {
                fprintf(stderr, "Error: fork() returned %d errno %d\n", pid, errno);
                return false;
            }
            if (pid > 0) // Parent process, pid is child process id
            {
                return true;
            }
            // Child process falls through to rest of initialization

            pid_t sid = setsid();
            if (sid < 0)
                fprintf(stderr, "Error: setsid() returned %d errno %d\n", sid, errno);
        }
#endif
        SoftSetBoolArg("-server", true);

        // Set this early so that parameter interactions go to console
        InitLogging();
        InitParameterInteraction();
        fRet = AppInit2(config, threadGroup, scheduler);
    }
    catch (const std::exception &e)
    {
        PrintExceptionContinue(&e, "AppInit()");
    }
    catch (...)
    {
        PrintExceptionContinue(NULL, "AppInit()");
    }

    if (!fRet)
    {
        Interrupt(threadGroup);
        // threadGroup.join_all(); was left out intentionally here, because we didn't re-test all of
        // the startup-failure cases to make sure they don't result in a hang due to some
        // thread-blocking-waiting-for-another-thread-during-startup case
    }
    else
    {
        WaitForShutdown(&threadGroup);
    }
    Shutdown();

    return fRet;
}

int main(int argc, char *argv[])
{
    SetupEnvironment();

    // Connect solbitd signal handlers
    noui_connect();

    return (AppInit(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE);
}
