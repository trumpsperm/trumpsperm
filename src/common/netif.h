// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_COMMON_NETIF_H
#define BITCOINII_COMMON_NETIF_H

#include <netaddress.h>

#include <optional>

//! Query the OS for the default gateway for `network`. This only makes sense for NET_IPV4 and NET_IPV6.
//! Returns std::nullopt if it cannot be found, or there is no support for this OS.
std::optional<CNetAddr> QueryDefaultGateway(Network network);

//! Return all local non-loopback IPv4 and IPv6 network addresses.
std::vector<CNetAddr> GetLocalAddresses();

#endif // BITCOINII_COMMON_NETIF_H
