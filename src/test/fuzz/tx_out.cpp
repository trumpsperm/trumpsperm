// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <consensus/validation.h>
#include <core_memusage.h>
#include <policy/feerate.h>
#include <policy/policy.h>
#include <primitives/transaction.h>
#include <streams.h>
#include <test/fuzz/fuzz.h>

FUZZ_TARGET(tx_out)
{
    DataStream ds{buffer};
    CTxOut tx_out;
    try {
        ds >> tx_out;
    } catch (const std::ios_base::failure&) {
        return;
    }

    const CFeeRate dust_relay_fee{DUST_RELAY_TX_FEE};
    (void)GetDustThreshold(tx_out, dust_relay_fee);
    (void)IsDust(tx_out, dust_relay_fee);
    (void)RecursiveDynamicUsage(tx_out);

    (void)tx_out.ToString();
    (void)tx_out.IsNull();
    tx_out.SetNull();
    assert(tx_out.IsNull());
}
