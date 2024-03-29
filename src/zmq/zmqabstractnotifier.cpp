// Copyright (c) 2015 The Solbit Core developers
// Copyright (c) 2015-2018 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "zmqabstractnotifier.h"
#include "util.h"


CZMQAbstractNotifier::~CZMQAbstractNotifier() { assert(!psocket); }
bool CZMQAbstractNotifier::NotifyBlock(const CBlockIndex * /*CBlockIndex*/) { return true; }
bool CZMQAbstractNotifier::NotifyTransaction(const CTransactionRef & /*transaction*/) { return true; }
