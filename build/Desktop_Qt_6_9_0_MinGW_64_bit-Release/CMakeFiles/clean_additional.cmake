# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\CampusNavigation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CampusNavigation_autogen.dir\\ParseCache.txt"
  "CampusNavigation_autogen"
  )
endif()
