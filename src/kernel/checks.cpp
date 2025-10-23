// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <kernel/checks.h>

#include <random.h>
#include <util/result.h>
#include <util/translation.h>

#include <memory>

namespace kernel {

util::Result<void> SanityChecks(const Context&)
{
    if (!Random_SanityCheck()) {
        return util::Error{Untranslated("OS cryptographic RNG sanity check failure. Aborting.")};
    }

    return {};
}

}
