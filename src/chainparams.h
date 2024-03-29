// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_CHAINPARAMS_H
#define SOLBIT_CHAINPARAMS_H

#include "chainparamsbase.h"
#include "consensus/params.h"
#include "primitives/block.h"
#include "protocol.h"

#include <vector>

struct CDNSSeedData
{
    std::string name, host;
    bool supportsServiceBitsFiltering;
    CDNSSeedData(const std::string &strName, const std::string &strHost, bool supportsServiceBitsFilteringIn = false)
        : name(strName), host(strHost), supportsServiceBitsFiltering(supportsServiceBitsFilteringIn)
    {
    }
};

struct SeedSpec6
{
    uint8_t addr[16];
    uint16_t port;
};

typedef std::map<int, uint256> MapCheckpoints;

struct CCheckpointData
{
    MapCheckpoints mapCheckpoints;
    int64_t nTimeLastCheckpoint;
    uint64_t nTransactionsLastCheckpoint;
    double fTransactionsPerDay;
};

enum
{
    DEFAULT_MAINNET_PORT = 9773,
    DEFAULT_TESTNET_PORT = 19773,
    DEFAULT_NOLNET_PORT = 19873,
    DEFAULT_REGTESTNET_PORT = 19888
};

/**
 * CChainParams defines various tweakable parameters of a given instance of the
 * Solbit system. There are three: the main network on which people trade goods
 * and services, the public test network which gets reset from time to time and
 * a regression test mode which is intended for private networks only. It has
 * minimal difficulty to ensure that blocks can be found instantly.
 */
class CChainParams
{
public:
    enum Base58Type
    {
        PUBKEY_ADDRESS,
        SCRIPT_ADDRESS,
        SECRET_KEY,
        EXT_PUBLIC_KEY,
        EXT_SECRET_KEY,

        MAX_BASE58_TYPES
    };

    const Consensus::Params &GetConsensus() const { return consensus; }
    /** Modifiable consensus parameters added by bip135, is not threadsafe, only use during initializtion */
    Consensus::Params &GetModifiableConsensus() { return consensus; }
    const CMessageHeader::MessageStartChars &MessageStart() const { return pchMessageStart; }
    const CMessageHeader::MessageStartChars &CashMessageStart() const { return pchCashMessageStart; }
    int GetDefaultPort() const { return nDefaultPort; }
    const CBlock &GenesisBlock() const { return genesis; }
    /** Make miner wait to have peers to avoid wasting work */
    bool MiningRequiresPeers() const { return fMiningRequiresPeers; }
    /** Default value for -checkmempool and -checkblockindex argument */
    bool DefaultConsistencyChecks() const { return fDefaultConsistencyChecks; }
    /** Policy: Filter transactions that do not match well-defined patterns */
    bool RequireStandard() const;
    uint64_t PruneAfterHeight() const { return nPruneAfterHeight; }
    /** Make miner stop after a block is found. In RPC, don't return until nGenProcLimit blocks are generated */
    bool MineBlocksOnDemand() const { return fMineBlocksOnDemand; }
    /** In the future use NetworkIDString() for RPC fields */
    bool TestnetToBeDeprecatedFieldRPC() const { return fTestnetToBeDeprecatedFieldRPC; }
    /** Return the BIP70 network string (main, test or regtest) */
    std::string NetworkIDString() const { return strNetworkID; }
    const std::vector<CDNSSeedData> &DNSSeeds() const { return vSeeds; }
    const std::vector<uint8_t> &Base58Prefix(Base58Type type) const { return base58Prefixes[type]; }
    const std::string &CashAddrPrefix() const { return cashaddrPrefix; }
    const std::vector<SeedSpec6> &FixedSeeds() const { return vFixedSeeds; }
    const CCheckpointData &Checkpoints() const { return checkpointData; }
protected:
    CChainParams() {}
    Consensus::Params consensus;
    CMessageHeader::MessageStartChars pchMessageStart;
    CMessageHeader::MessageStartChars pchCashMessageStart;
    int nDefaultPort;
    uint64_t nPruneAfterHeight;
    std::vector<CDNSSeedData> vSeeds;
    std::vector<uint8_t> base58Prefixes[MAX_BASE58_TYPES];
    std::string cashaddrPrefix;
    std::string strNetworkID;
    CBlock genesis;
    std::vector<SeedSpec6> vFixedSeeds;
    bool fMiningRequiresPeers;
    bool fDefaultConsistencyChecks;
    bool fRequireStandard;
    bool fMineBlocksOnDemand;
    bool fTestnetToBeDeprecatedFieldRPC;
    CCheckpointData checkpointData;
};

/**
 * Return the currently selected parameters. This won't change after app
 * startup, except for unit tests.
 */
const CChainParams &Params();

/**
 * @returns CChainParams for the given BIP70 chain name.
 */
CChainParams &Params(const std::string &chain);

/**
 * Sets the params returned by Params() to those for the given BIP70 chain name.
 * @throws std::runtime_error when the chain is not supported.
 */
void SelectParams(const std::string &chain);

CBlock CreateGenesisBlock(CScript prefix,
    const std::string &comment,
    const CScript &genesisOutputScript,
    uint32_t nTime,
    uint32_t nNonce,
    uint32_t nBits,
    int32_t nVersion,
    const CAmount &genesisReward);

// bip135 begin
/**
 * Return the currently selected parameters. Can be changed by reading in
 * some additional config files (e.g. CSV deployment data)
 *
 * This can only be used during initialization because modification is not threadsafe
 */
CChainParams &ModifiableParams();

/**
 * Returns true if a deployment is considered active on a particular network
 */

bool IsConfiguredDeployment(const Consensus::Params &consensusParams, const int bit);

/**
 * Dump the fork deployment parameters for the given BIP70 chain name.
 * @throws std::runtime_error when the chain is not supported.
 */
const std::string NetworkDeploymentInfoCSV(const std::string &chain);
// bip135 end

#endif // SOLBIT_CHAINPARAMS_H
