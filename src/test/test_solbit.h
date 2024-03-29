#ifndef SOLBIT_TEST_TEST_SOLBIT_H
#define SOLBIT_TEST_TEST_SOLBIT_H

#include "chainparamsbase.h"
#include "fs.h"
#include "key.h"
#include "pubkey.h"
#include "txdb.h"
#include "txmempool.h"

#include <boost/thread.hpp>

/** Basic testing setup.
 * This just configures logging and chain parameters.
 */
struct BasicTestingSetup
{
    ECCVerifyHandle globalVerifyHandle;

    BasicTestingSetup(const std::string &chainName = CBaseChainParams::MAIN);
    ~BasicTestingSetup();
};

/** Testing setup that configures a complete environment.
 * Included are data directory, coins database, script check threads setup.
 */
struct TestingSetup : public BasicTestingSetup
{
    CCoinsViewDB *pcoinsdbview;
    fs::path pathTemp;
    boost::thread_group threadGroup;

    TestingSetup(const std::string &chainName = CBaseChainParams::MAIN);
    ~TestingSetup();
};

class CBlock;
struct CMutableTransaction;
class CScript;

//
// Testing fixture that pre-creates a
// 100-block REGTEST-mode block chain
//
struct TestChain100Setup : public TestingSetup
{
    TestChain100Setup();

    // Create a new block with just given transactions, coinbase paying to
    // scriptPubKey, and try to add it to the current chain.
    CBlock CreateAndProcessBlock(const std::vector<CMutableTransaction> &txns, const CScript &scriptPubKey);

    ~TestChain100Setup();

    std::vector<CTransaction> coinbaseTxns; // For convenience, coinbase transactions
    CKey coinbaseKey; // private/public key needed to spend coinbase transactions
};

class CTxMemPoolEntry;
class CTxMemPool;

struct TestMemPoolEntryHelper
{
    // Default values
    CAmount nFee;
    int64_t nTime;
    double dPriority;
    unsigned int nHeight;
    bool hadNoDependencies;
    bool spendsCoinbase;
    unsigned int sigOpCount;
    LockPoints lp;

    TestMemPoolEntryHelper()
        : nFee(0), nTime(0), dPriority(0.0), nHeight(1), hadNoDependencies(false), spendsCoinbase(false), sigOpCount(1)
    {
    }

    CTxMemPoolEntry FromTx(const CMutableTransaction &tx, CTxMemPool *pool = nullptr);
    CTxMemPoolEntry FromTx(const CTransaction &tx, CTxMemPool *pool = nullptr);

    // Change the default value
    TestMemPoolEntryHelper &Fee(CAmount _fee)
    {
        nFee = _fee;
        return *this;
    }
    TestMemPoolEntryHelper &Time(int64_t _time)
    {
        nTime = _time;
        return *this;
    }
    TestMemPoolEntryHelper &Priority(double _priority)
    {
        dPriority = _priority;
        return *this;
    }
    TestMemPoolEntryHelper &Height(unsigned int _height)
    {
        nHeight = _height;
        return *this;
    }
    TestMemPoolEntryHelper &HadNoDependencies(bool _hnd)
    {
        hadNoDependencies = _hnd;
        return *this;
    }
    TestMemPoolEntryHelper &SpendsCoinbase(bool _flag)
    {
        spendsCoinbase = _flag;
        return *this;
    }
    TestMemPoolEntryHelper &SigOps(unsigned int _sigops)
    {
        sigOpCount = _sigops;
        return *this;
    }
};

// define an implicit conversion here so that uint256 may be used directly in BOOST_CHECK_*
std::ostream &operator<<(std::ostream &os, const uint256 &num);


#endif
