// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#if defined(HAVE_CONFIG_H)
#include "config/solbit-config.h"
#endif

#include "utiltime.h"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>

using namespace std;

static int64_t nMockTime = 0; //! For unit testing

int64_t GetTime()
{
    if (nMockTime)
        return nMockTime;

    time_t now = time(nullptr);
    assert(now > 0);
    return now;
}

void SetMockTime(int64_t nMockTimeIn) { nMockTime = nMockTimeIn; }
int64_t GetTimeMillis()
{
    int64_t now = (boost::posix_time::microsec_clock::universal_time() -
                      boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1)))
                      .total_milliseconds();
    assert(now > 0);
    return now;
}

int64_t GetTimeMicros()
{
    int64_t now = (boost::posix_time::microsec_clock::universal_time() -
                      boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1)))
                      .total_microseconds();
    assert(now > 0);
    return now;
}

#ifdef WIN32
uint64_t GetStopwatch() { return 1000 * GetTimeMicros(); }
#elif MAC_OSX
uint64_t GetStopwatch() { return 1000 * GetTimeMicros(); }
#else
uint64_t GetStopwatch()
{
    struct timespec t;
    if (clock_gettime(CLOCK_MONOTONIC, &t) == 0)
    {
        uint64_t ret = t.tv_sec;
        ret *= 1000ULL * 1000ULL * 1000ULL; // convert sec to nsec
        ret += t.tv_nsec;
        return ret;
    }
    return 0;
}
#endif

/** Return a time useful for the debug log */
int64_t GetLogTimeMicros()
{
    if (nMockTime)
        return nMockTime * 1000000;

    return GetTimeMicros();
}

void MilliSleep(int64_t n)
{
/**
 * Boost's sleep_for was uninterruptable when backed by nanosleep from 1.50
 * until fixed in 1.52. Use the deprecated sleep method for the broken case.
 * See: https://svn.boost.org/trac/boost/ticket/7238
 */
#if defined(HAVE_WORKING_BOOST_SLEEP_FOR)
    boost::this_thread::sleep_for(boost::chrono::milliseconds(n));
#elif defined(HAVE_WORKING_BOOST_SLEEP)
    boost::this_thread::sleep(boost::posix_time::milliseconds(n));
#else
// should never get here
#error missing boost sleep implementation
#endif
}

std::string DateTimeStrFormat(const char *pszFormat, int64_t nTime)
{
    // std::locale takes ownership of the pointer
    std::locale loc(std::locale::classic(), new boost::posix_time::time_facet(pszFormat));
    std::stringstream ss;
    ss.imbue(loc);
    ss << boost::posix_time::from_time_t(nTime);
    return ss.str();
}
