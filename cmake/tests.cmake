# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The BitcoinII Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

if(TARGET bitcoinII-util AND TARGET bitcoinII-tx AND PYTHON_COMMAND)
  add_test(NAME util_test_runner
    COMMAND ${CMAKE_COMMAND} -E env BITCOINIIUTIL=$<TARGET_FILE:bitcoinII-util> BITCOINIITX=$<TARGET_FILE:bitcoinII-tx> ${PYTHON_COMMAND} ${PROJECT_BINARY_DIR}/test/util/test_runner.py
  )
endif()

if(PYTHON_COMMAND)
  add_test(NAME util_rpcauth_test
    COMMAND ${PYTHON_COMMAND} ${PROJECT_BINARY_DIR}/test/util/rpcauth-test.py
  )
endif()
