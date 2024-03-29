// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_NODESTATE_H
#define SOLBIT_NODESTATE_H

#include "net.h" // For NodeId

/**
* Maintain validation-specific state about nodes, protected by cs_main, instead
* by CNode's own locks. This simplifies asynchronous operation, where
* processing of incoming data is done after the ProcessMessage call returns,
* and we're no longer holding the node's locks.
*/
struct CNodeState
{
    //! The peer's address
    CService address;
    //! String name of this peer (debugging/logging purposes).
    std::string name;
    //! The best known block we know this peer has announced.
    CBlockIndex *pindexBestKnownBlock;
    //! The hash of the last unknown block this peer has announced.
    uint256 hashLastUnknownBlock;
    //! The last full block we both have.
    CBlockIndex *pindexLastCommonBlock;
    //! The best header we have sent our peer.
    CBlockIndex *pindexBestHeaderSent;
    //! Whether we've started headers synchronization with this peer.
    bool fSyncStarted;
    //! The start time of the sync
    int64_t nSyncStartTime;
    //! Were the first headers requested in a sync received
    bool fFirstHeadersReceived;
    //! Our current block height at the time we requested GETHEADERS
    int nFirstHeadersExpectedHeight;
    //! During IBD we need to update the block availabiity for each peer. We do this by requesting a header
    //  when a peer connects and also when we ask for the initial set of all headers.
    bool fRequestedInitialBlockAvailability;
    //! Whether we consider this a preferred download peer.
    bool fPreferredDownload;
    //! Whether this peer wants invs or headers (when possible) for block announcements.
    bool fPreferHeaders;

    CNodeState(CAddress addrIn, std::string addrNameIn);
};

/** Map maintaining per-node state. Requires cs_main. */
extern std::map<NodeId, CNodeState> mapNodeState;

// Requires cs_main.
extern CNodeState *State(NodeId nId);

#endif // SOLBIT_NODESTATE_H
