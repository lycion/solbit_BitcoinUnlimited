// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_CONSENSUS_CONSENSUS_H
#define SOLBIT_CONSENSUS_CONSENSUS_H

/** The maximum allowed size for a serialized block, in bytes (network rule) */
// BU: this constant is deprecated but is still used in a few areas such as allocation of memory.  Removing it is a
// tradeoff between being perfect and changing more code. TODO: remove this entirely
// static const unsigned int BU_MAX_BLOCK_SIZE = 32000000;
static const unsigned int BLOCKSTREAM_CORE_MAX_BLOCK_SIZE = 1000000;
/** The maximum allowed number of signature check operations in a 1MB block (network rule), and the suggested max sigops
 * per (MB rounded up) in blocks > 1MB.  If greater, the block is considered excessive */
static const unsigned int BLOCKSTREAM_CORE_MAX_BLOCK_SIGOPS = BLOCKSTREAM_CORE_MAX_BLOCK_SIZE / 50;
static const unsigned int MAX_TX_SIGOPS = BLOCKSTREAM_CORE_MAX_BLOCK_SIZE / 50;
/** The maximum suggested length of a transaction.  If greater, the transaction is not relayed, and the > 1MB block is
   considered "excessive".
    For blocks < 1MB, there is no largest transaction so it is defacto 1MB.
*/
static const unsigned int DEFAULT_LARGEST_TRANSACTION = 1000000;

/** This is the default max bloom filter size allowed on the solbit network.  In Solbit Unlimited we have the ability
 *  to communicate to our peer what max bloom filter size we will accept but still observe this value as a default.
 */
static const unsigned int SMALLEST_MAX_BLOOM_FILTER_SIZE = 36000; // bytes

/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int COINBASE_MATURITY = 100;

/** Flags for nSequence and nLockTime locks */
enum
{
    /* Interpret sequence numbers as relative lock-time constraints. */
    LOCKTIME_VERIFY_SEQUENCE = (1 << 0),

    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};

#endif // SOLBIT_CONSENSUS_CONSENSUS_H
