# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The BitcoinII Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

add_library(bitcoinII_util STATIC EXCLUDE_FROM_ALL
  asmap.cpp
  batchpriority.cpp
  bip32.cpp
  bytevectorhash.cpp
  chaintype.cpp
  check.cpp
  exception.cpp
  feefrac.cpp
  fs.cpp
  fs_helpers.cpp
  hasher.cpp
  moneystr.cpp
  rbf.cpp
  readwritefile.cpp
  serfloat.cpp
  signalinterrupt.cpp
  sock.cpp
  strencodings.cpp
  string.cpp
  syserror.cpp
  thread.cpp
  threadinterrupt.cpp
  threadnames.cpp
  time.cpp
  tokenpipe.cpp
  ../logging.cpp
  ../random.cpp
  ../randomenv.cpp
  ../streams.cpp
  ../support/lockedpool.cpp
  ../sync.cpp
)

target_link_libraries(bitcoinII_util
  PRIVATE
    core_interface
    bitcoinII_clientversion
    bitcoinII_crypto
    $<$<PLATFORM_ID:Windows>:ws2_32>
    $<$<PLATFORM_ID:Windows>:iphlpapi>
)
