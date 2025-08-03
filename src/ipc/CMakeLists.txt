# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The BitcoinII Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

add_library(bitcoinII_ipc STATIC EXCLUDE_FROM_ALL
  capnp/mining.cpp
  capnp/protocol.cpp
  interfaces.cpp
  process.cpp
)

target_capnp_sources(bitcoinII_ipc ${PROJECT_SOURCE_DIR}
  capnp/common.capnp
  capnp/echo.capnp
  capnp/init.capnp
  capnp/mining.capnp
)

target_link_libraries(bitcoinII_ipc
  PRIVATE
    core_interface
    univalue
)
