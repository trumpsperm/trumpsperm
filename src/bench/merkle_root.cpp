// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <bench/bench.h>
#include <consensus/merkle.h>
#include <random.h>
#include <uint256.h>

#include <vector>

static void MerkleRoot(benchmark::Bench& bench)
{
    FastRandomContext rng(true);
    std::vector<uint256> leaves;
    leaves.resize(9001);
    for (auto& item : leaves) {
        item = rng.rand256();
    }
    bench.batch(leaves.size()).unit("leaf").run([&] {
        bool mutation = false;
        uint256 hash = ComputeMerkleRoot(std::vector<uint256>(leaves), &mutation);
        leaves[mutation] = hash;
    });
}

BENCHMARK(MerkleRoot, benchmark::PriorityLevel::HIGH);
