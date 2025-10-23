// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_UTIL_THREADNAMES_H
#define BITCOINII_UTIL_THREADNAMES_H

#include <string>

namespace util {
//! Rename a thread both in terms of an internal (in-memory) name as well
//! as its system thread name.
//! @note Do not call this for the main thread, as this will interfere with
//! UNIX utilities such as top and killall. Use ThreadSetInternalName instead.
void ThreadRename(const std::string&);

//! Set the internal (in-memory) name of the current thread only.
void ThreadSetInternalName(const std::string&);

//! Get the thread's internal (in-memory) name; used e.g. for identification in
//! logging.
std::string ThreadGetInternalName();

} // namespace util

#endif // BITCOINII_UTIL_THREADNAMES_H
