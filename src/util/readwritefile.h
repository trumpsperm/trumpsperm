// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_UTIL_READWRITEFILE_H
#define BITCOINII_UTIL_READWRITEFILE_H

#include <util/fs.h>

#include <limits>
#include <string>
#include <utility>

/** Read full contents of a file and return them in a std::string.
 * Returns a pair <status, string>.
 * If an error occurred, status will be false, otherwise status will be true and the data will be returned in string.
 *
 * @param maxsize Puts a maximum size limit on the file that is read. If the file is larger than this, truncated data
 *         (with len > maxsize) will be returned.
 */
std::pair<bool,std::string> ReadBinaryFile(const fs::path &filename, size_t maxsize=std::numeric_limits<size_t>::max());

/** Write contents of std::string to a file.
 * @return true on success.
 */
bool WriteBinaryFile(const fs::path &filename, const std::string &data);

#endif // BITCOINII_UTIL_READWRITEFILE_H
