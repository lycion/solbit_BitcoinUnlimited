// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_SCRIPT_SIGCACHE_H
#define SOLBIT_SCRIPT_SIGCACHE_H

#include "script/interpreter.h"

#include <vector>

// DoS prevention: limit cache size to less than 40MB (over 500000
// entries on 64-bit systems).
static const unsigned int DEFAULT_MAX_SIG_CACHE_SIZE = 40;

class CPubKey;

class CachingTransactionSignatureChecker : public TransactionSignatureChecker
{
private:
    bool store;

public:
    CachingTransactionSignatureChecker(const CTransaction *txToIn,
        unsigned int nInIn,
        const CAmount &amountIn,
        unsigned int flags,
        bool storeIn = true)
        : TransactionSignatureChecker(txToIn, nInIn, amountIn, flags), store(storeIn)
    {
    }

    bool VerifySignature(const std::vector<unsigned char> &vchSig,
        const CPubKey &vchPubKey,
        const uint256 &sighash) const;
};

#endif // SOLBIT_SCRIPT_SIGCACHE_H
