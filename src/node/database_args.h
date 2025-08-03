// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_NODE_DATABASE_ARGS_H
#define BITCOINII_NODE_DATABASE_ARGS_H

class ArgsManager;
struct DBOptions;

namespace node {
void ReadDatabaseArgs(const ArgsManager& args, DBOptions& options);
} // namespace node

#endif // BITCOINII_NODE_DATABASE_ARGS_H
