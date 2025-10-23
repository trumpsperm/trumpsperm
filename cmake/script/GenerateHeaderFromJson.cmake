# Copyright (c) 2009-2025 Satoshi Nakamoto
# Copyright (c) 2009-2025 The Bitcoin Core developers
# Copyright (c) 2024-2025 The Trumpsperm Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

cmake_path(GET JSON_SOURCE_PATH STEM json_source_basename)

file(READ ${JSON_SOURCE_PATH} hex_content HEX)
string(REGEX REPLACE "................" "\\0\n" formatted_bytes "${hex_content}")
string(REGEX REPLACE "[^\n][^\n]" "'\\\\x\\0'," formatted_bytes "${formatted_bytes}")

set(header_content
"#include <string_view>

namespace json_tests {
inline constexpr char detail_${json_source_basename}_bytes[] {
${formatted_bytes}
};

inline constexpr std::string_view ${json_source_basename}{std::begin(detail_${json_source_basename}_bytes), std::end(detail_${json_source_basename}_bytes)};
}
")
file(WRITE ${HEADER_PATH} "${header_content}")
