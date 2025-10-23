// Copyright (c) 2009-2025 Satoshi Nakamoto
// Copyright (c) 2009-2025 The Bitcoin Core developers
// Copyright (c) 2024-2025 The BitcoinII Core developers
// Copyright (c) 2025 The Trumpsperm Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <test/util/blockfilter.h>

#include <chainparams.h>
#include <node/blockstorage.h>
#include <primitives/block.h>
#include <undo.h>
#include <validation.h>

using node::BlockManager;

bool ComputeFilter(BlockFilterType filter_type, const CBlockIndex& block_index, BlockFilter& filter, const BlockManager& blockman)
{
    LOCK(::cs_main);

    CBlock block;
    if (!blockman.ReadBlock(block, block_index.GetBlockPos())) {
        return false;
    }

    CBlockUndo block_undo;
    if (block_index.nHeight > 0 && !blockman.ReadBlockUndo(block_undo, block_index)) {
        return false;
    }

    filter = BlockFilter(filter_type, block, block_undo);
    return true;
}
