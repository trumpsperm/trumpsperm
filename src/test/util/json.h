// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_TEST_UTIL_JSON_H
#define BITCOINII_TEST_UTIL_JSON_H

#include <univalue.h>

#include <string_view>

UniValue read_json(std::string_view jsondata);

#endif // BITCOINII_TEST_UTIL_JSON_H
