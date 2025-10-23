# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The Trumpsperm Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

target_sources(fuzz
  PRIVATE
    coincontrol.cpp
    coinselection.cpp
    crypter.cpp
    fees.cpp
    $<$<BOOL:${USE_SQLITE}>:${CMAKE_CURRENT_LIST_DIR}/notifications.cpp>
    $<$<BOOL:${USE_SQLITE}>:${CMAKE_CURRENT_LIST_DIR}/scriptpubkeyman.cpp>
    spend.cpp
    wallet_bdb_parser.cpp
)
target_link_libraries(fuzz trumpsperm_wallet)
