# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The BitcoinII Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

function(generate_setup_nsi)
  set(abs_top_srcdir ${PROJECT_SOURCE_DIR})
  set(abs_top_builddir ${PROJECT_BINARY_DIR})
  set(CLIENT_URL ${PROJECT_HOMEPAGE_URL})
  set(CLIENT_TARNAME "bitcoinII")
  set(BITCOINII_GUI_NAME "bitcoinII-qt")
  set(BITCOINII_DAEMON_NAME "bitcoinIId")
  set(BITCOINII_CLI_NAME "bitcoinII-cli")
  set(BITCOINII_TX_NAME "bitcoinII-tx")
  set(BITCOINII_WALLET_TOOL_NAME "bitcoinII-wallet")
  set(BITCOINII_TEST_NAME "test_bitcoinII")
  set(EXEEXT ${CMAKE_EXECUTABLE_SUFFIX})
  configure_file(${PROJECT_SOURCE_DIR}/share/setup.nsi.in ${PROJECT_BINARY_DIR}/bitcoinII-win64-setup.nsi USE_SOURCE_PERMISSIONS @ONLY)
endfunction()
