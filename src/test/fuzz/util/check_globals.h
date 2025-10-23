// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_TEST_FUZZ_UTIL_CHECK_GLOBALS_H
#define BITCOINII_TEST_FUZZ_UTIL_CHECK_GLOBALS_H

#include <atomic>
#include <memory>
#include <optional>
#include <string>

extern std::atomic<bool> g_used_system_time;

struct CheckGlobalsImpl;
struct CheckGlobals {
    CheckGlobals();
    ~CheckGlobals();
    std::unique_ptr<CheckGlobalsImpl> m_impl;
};

#endif // BITCOINII_TEST_FUZZ_UTIL_CHECK_GLOBALS_H
