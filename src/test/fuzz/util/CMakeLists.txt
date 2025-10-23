# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The Trumpsperm Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

add_library(test_fuzz STATIC EXCLUDE_FROM_ALL
  check_globals.cpp
  descriptor.cpp
  mempool.cpp
  net.cpp
  ../fuzz.cpp
  ../util.cpp
)

target_link_libraries(test_fuzz
  PRIVATE
    core_interface
    test_util
    trumpsperm_node
    Boost::headers
)

if(NOT FUZZ_BINARY_LINKS_WITHOUT_MAIN_FUNCTION)
  target_compile_definitions(test_fuzz PRIVATE PROVIDE_FUZZ_MAIN_FUNCTION)
endif()
