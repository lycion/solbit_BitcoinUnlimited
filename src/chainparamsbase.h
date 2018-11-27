// Copyright (c) 2014-2015 The Solbit Core developers
// Copyright (c) 2015-2017 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_CHAINPARAMSBASE_H
#define SOLBIT_CHAINPARAMSBASE_H

#include <string>
#include <vector>

/**
 * CBaseChainParams defines the base parameters (shared between solbit-cli and solbitd)
 * of a given instance of the Solbit system.
 */
class CBaseChainParams
{
public:
    /** BIP70 chain name strings (main, test or regtest) */
    static const std::string MAIN;
    static const std::string UNL;
    static const std::string TESTNET;
    static const std::string REGTEST;

    const std::string &DataDir() const { return strDataDir; }
    int RPCPort() const { return nRPCPort; }
protected:
    CBaseChainParams() {}
    int nRPCPort;
    std::string strDataDir;
};

/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CBaseChainParams &BaseParams();

CBaseChainParams &BaseParams(const std::string &chain);

/** Sets the params returned by Params() to those for the given network. */
void SelectBaseParams(const std::string &chain);

/**
 * Looks for -regtest, -testnet and returns the appropriate BIP70 chain name.
 * @return CBaseChainParams::MAX_NETWORK_TYPES if an invalid combination is given. CBaseChainParams::MAIN by default.
 */
std::string ChainNameFromCommandLine();

/**
 * Return true if SelectBaseParamsFromCommandLine() has been called to select
 * a network.
 */
bool AreBaseParamsConfigured();

#endif // SOLBIT_CHAINPARAMSBASE_H
