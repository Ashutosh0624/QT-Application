# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Radio-Station_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Radio-Station_autogen.dir\\ParseCache.txt"
  "Radio-Station_autogen"
  )
endif()
