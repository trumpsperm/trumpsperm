# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The Trumpsperm Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

include_guard(GLOBAL)

# Avoid the directory-wide add_definitions() and add_compile_definitions() commands.
# Instead, prefer the target-specific target_compile_definitions() one.
get_directory_property(global_compile_definitions COMPILE_DEFINITIONS)
if(global_compile_definitions)
  message(AUTHOR_WARNING "The directory's COMPILE_DEFINITIONS property is not empty: ${global_compile_definitions}")
endif()

# Avoid the directory-wide add_compile_options() command.
# Instead, prefer the target-specific target_compile_options() one.
get_directory_property(global_compile_options COMPILE_OPTIONS)
if(global_compile_options)
  message(AUTHOR_WARNING "The directory's COMPILE_OPTIONS property is not empty: ${global_compile_options}")
endif()

# Avoid the directory-wide add_link_options() command.
# Instead, prefer the target-specific target_link_options() one.
get_directory_property(global_link_options LINK_OPTIONS)
if(global_link_options)
  message(AUTHOR_WARNING "The directory's LINK_OPTIONS property is not empty: ${global_link_options}")
endif()

# Avoid the directory-wide link_libraries() command.
# Instead, prefer the target-specific target_link_libraries() one.
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/dummy_cxx_source.cpp "#error")
add_library(check_loose_linked_libraries OBJECT EXCLUDE_FROM_ALL ${CMAKE_CURRENT_BINARY_DIR}/dummy_cxx_source.cpp)
set_target_properties(check_loose_linked_libraries PROPERTIES EXPORT_COMPILE_COMMANDS OFF)
get_target_property(global_linked_libraries check_loose_linked_libraries LINK_LIBRARIES)
if(global_linked_libraries)
  message(AUTHOR_WARNING "There are libraries linked with `link_libraries` commands: ${global_linked_libraries}")
endif()
