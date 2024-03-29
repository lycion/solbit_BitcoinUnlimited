// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_PRIMITIVES_BLOCK_H
#define SOLBIT_PRIMITIVES_BLOCK_H

#include "primitives/transaction.h"
#include "serialize.h"
#include "sync.h"
#include "uint256.h"

const uint32_t BIP_009_MASK = 0x20000000;
const uint32_t BASE_VERSION = 0x20000000;
const uint32_t FORK_BIT_2MB = 0x10000000; // Vote for 2MB fork
const bool DEFAULT_2MB_VOTE = false;

/** Nodes collect new transactions into a block, hash them into a hash tree,
 * and scan through nonce values to make the block's hash satisfy proof-of-work
 * requirements.  When they solve the proof-of-work, they broadcast the block
 * to everyone and the block is added to the block chain.  The first transaction
 * in the block is a special one that creates a new coin owned by the creator
 * of the block.
 */
class CBlockHeader
{
public:
    // header
    static const int32_t CURRENT_VERSION = BASE_VERSION;
    int32_t nVersion;
    uint256 hashPrevBlock;
    uint256 hashMerkleRoot;
    uint32_t nTime;
    uint32_t nBits;
    uint32_t nNonce;

    CBlockHeader() { SetNull(); }
    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream &s, Operation ser_action)
    {
        READWRITE(this->nVersion);
        READWRITE(hashPrevBlock);
        READWRITE(hashMerkleRoot);
        READWRITE(nTime);
        READWRITE(nBits);
        READWRITE(nNonce);
    }

    void SetNull()
    {
        nVersion = 0;
        hashPrevBlock.SetNull();
        hashMerkleRoot.SetNull();
        nTime = 0;
        nBits = 0;
        nNonce = 0;
    }

    bool IsNull() const { return (nBits == 0); }
    uint256 GetHash() const;

    int64_t GetBlockTime() const { return (int64_t)nTime; }
};


class CBlock : public CBlockHeader
{
private:
    // memory only
    mutable uint64_t nBlockSize; // Serialized block size in bytes

public:
    // network and disk
    std::vector<CTransactionRef> vtx;

    // memory only
    // 0.11: mutable std::vector<uint256> vMerkleTree;
    mutable bool fChecked;
    mutable bool fExcessive; // BU: is the block "excessive" (bigger than this node prefers to accept)

    CBlock() { SetNull(); }
    CBlock(const CBlockHeader &header)
    {
        SetNull();
        *((CBlockHeader *)this) = header;
    }

    // return the index of the transaction in this block.  Return -1 if tx is not in this block
    int find(uint256 hash) const
    {
        int nIndex;
        for (nIndex = 0; nIndex < (int)vtx.size(); nIndex++)
            if (vtx[nIndex] == *(CTransactionRef *)this)
                break;
        if (nIndex == (int)vtx.size())
        {
            nIndex = -1;
        }
        return nIndex;

#if 0 // efficient but unnecessary
        LOCK(csBlockHashToIdx);
        // If the hash to idx map is empty, then fill it up
        if (hashToIdx.empty()&& (!vtx.empty()))
        {
            for (int nIndex = 0; nIndex < (int)vtx.size(); nIndex++)
                hashToIdx[vtx[nIndex].GetHash()] = nIndex;
        }
        // find the hash and return the idx
        auto pos = hashToIdx.find(hash);
        if (pos == hashToIdx.end()) return -1;
        return pos->second;
#endif
    }

    static bool VersionKnown(int32_t nVersion, int32_t voteBits)
    {
        if (nVersion >= 1 && nVersion <= 4)
            return true;
        // BIP009 / versionbits:
        if (nVersion & BIP_009_MASK)
        {
            uint32_t v = nVersion & ~BIP_009_MASK;
            if ((v & ~voteBits) == 0)
                return true;
        }
        return false;
    }

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream &s, Operation ser_action)
    {
        READWRITE(*(CBlockHeader *)this);
        READWRITE(vtx);
    }

    uint64_t GetHeight() const // Returns the block's height as specified in its coinbase transaction
    {
        const CScript &sig = vtx[0]->vin[0].scriptSig;
        int numlen = sig[0];
        if (numlen == OP_0)
            return 0;
        if ((numlen >= OP_1) && (numlen <= OP_16))
            return numlen - OP_1 + 1;
        std::vector<unsigned char> heightScript(numlen);
        copy(sig.begin() + 1, sig.begin() + 1 + numlen, heightScript.begin());
        CScriptNum coinbaseHeight(heightScript, false, numlen);
        return coinbaseHeight.getint();
    }

    void SetNull()
    {
        CBlockHeader::SetNull();
        vtx.clear();
        // vMerkleTree.clear();
        fChecked = false;
        fExcessive = false;
        nBlockSize = 0;
    }

    CBlockHeader GetBlockHeader() const
    {
        CBlockHeader block;
        block.nVersion = nVersion;
        block.hashPrevBlock = hashPrevBlock;
        block.hashMerkleRoot = hashMerkleRoot;
        block.nTime = nTime;
        block.nBits = nBits;
        block.nNonce = nNonce;
        return block;
    }

    std::string ToString() const;

    // Return the serialized block size in bytes. This is only done once and then the result stored
    // in nBlockSize for future reference, saving unncessary and expensive serializations.
    uint64_t GetBlockSize() const;
};


/** Describes a place in the block chain to another node such that if the
 * other node doesn't have the same branch, it can find a recent common trunk.
 * The further back it is, the further before the fork it may be.
 */
struct CBlockLocator
{
    std::vector<uint256> vHave;

    CBlockLocator() {}
    CBlockLocator(const std::vector<uint256> &vHaveIn) { vHave = vHaveIn; }
    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream &s, Operation ser_action)
    {
        int nVersion = s.GetVersion();
        if (!(s.GetType() & SER_GETHASH))
            READWRITE(nVersion);
        READWRITE(vHave);
    }

    void SetNull() { vHave.clear(); }
    bool IsNull() const { return vHave.empty(); }
};

typedef std::shared_ptr<CBlock> CBlockRef;
typedef std::shared_ptr<const CBlock> ConstCBlockRef;

static inline CBlockRef MakeBlockRef() { return std::make_shared<CBlock>(); }
template <typename Blk>
static inline CBlockRef MakeBlockRef(Blk &&blkIn)
{
    return std::make_shared<CBlock>(std::forward<Blk>(blkIn));
}

#endif // SOLBIT_PRIMITIVES_BLOCK_H
