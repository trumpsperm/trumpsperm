// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINII_ATTRIBUTES_H
#define BITCOINII_ATTRIBUTES_H

#if defined(__clang__)
#  if __has_attribute(lifetimebound)
#    define LIFETIMEBOUND [[clang::lifetimebound]]
#  else
#    define LIFETIMEBOUND
#  endif
#else
#  define LIFETIMEBOUND
#endif

#if defined(__GNUC__)
#  define ALWAYS_INLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER)
#  define ALWAYS_INLINE __forceinline
#else
#  error No known always_inline attribute for this platform.
#endif

#endif // BITCOINII_ATTRIBUTES_H
