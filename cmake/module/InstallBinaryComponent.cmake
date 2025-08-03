# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The BitcoinII Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

include_guard(GLOBAL)
include(GNUInstallDirs)

function(install_binary_component component)
  cmake_parse_arguments(PARSE_ARGV 1
    IC                # prefix
    "HAS_MANPAGE"     # options
    ""                # one_value_keywords
    ""                # multi_value_keywords
  )
  set(target_name ${component})
  install(TARGETS ${target_name}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT ${component}
  )
  if(INSTALL_MAN AND IC_HAS_MANPAGE)
    install(FILES ${PROJECT_SOURCE_DIR}/doc/man/${target_name}.1
      DESTINATION ${CMAKE_INSTALL_MANDIR}/man1
      COMPONENT ${component}
    )
  endif()
endfunction()
