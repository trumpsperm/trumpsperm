// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_UTIL_INSERT_H
#define BITCOINII_UTIL_INSERT_H

#include <set>

namespace util {

//! Simplification of std insertion
template <typename Tdst, typename Tsrc>
inline void insert(Tdst& dst, const Tsrc& src) {
    dst.insert(dst.begin(), src.begin(), src.end());
}
template <typename TsetT, typename Tsrc>
inline void insert(std::set<TsetT>& dst, const Tsrc& src) {
    dst.insert(src.begin(), src.end());
}

} // namespace util

#endif // BITCOINII_UTIL_INSERT_H
