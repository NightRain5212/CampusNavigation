# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\aaa_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\aaa_autogen.dir\\ParseCache.txt"
  "aaa_autogen"
  )
endif()
