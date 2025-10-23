// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

//! @file common/types.h is a home for simple enum and struct type definitions
//! that can be used internally by functions in the libtrumpsperm_common library,
//! but also used externally by node, wallet, and GUI code.
//!
//! This file is intended to define only simple types that do not have external
//! dependencies. More complicated types should be defined in dedicated header
//! files.

#ifndef BITCOINII_COMMON_TYPES_H
#define BITCOINII_COMMON_TYPES_H

namespace common {
enum class PSBTError {
    MISSING_INPUTS,
    SIGHASH_MISMATCH,
    EXTERNAL_SIGNER_NOT_FOUND,
    EXTERNAL_SIGNER_FAILED,
    UNSUPPORTED,
};
} // namespace common

#endif // BITCOINII_COMMON_TYPES_H
