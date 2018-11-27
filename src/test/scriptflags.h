// Copyright (c) 2018 The Solbit developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SOLBIT_TEST_SCRIPTFLAGS_H
#define SOLBIT_TEST_SCRIPTFLAGS_H

#include <string>

uint32_t ParseScriptFlags(std::string strFlags);
std::string FormatScriptFlags(uint32_t flags);

#endif // SOLBIT_TEST_SCRIPTFLAGS_H
