#!/bin/sh
# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The Trumpsperm Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C

if [ -n "$SOURCE_DATE_EPOCH" ]; then
  find . -exec touch -d "@$SOURCE_DATE_EPOCH" {} +
fi

find . | sort | "$1" -X@ "$2"
