// Copyright (c) 2015 The Solbit Core developers
// Copyright (c) 2015-2017 The Solbit Unlimited developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_ZMQ_ZMQCONFIG_H
#define SOLBIT_ZMQ_ZMQCONFIG_H

#if defined(HAVE_CONFIG_H)
#include "config/solbit-config.h"
#endif

#include <stdarg.h>
#include <string>

#if ENABLE_ZMQ
#include <zmq.h>
#endif

#include "primitives/block.h"
#include "primitives/transaction.h"

void zmqError(const char *str);

#endif // SOLBIT_ZMQ_ZMQCONFIG_H
