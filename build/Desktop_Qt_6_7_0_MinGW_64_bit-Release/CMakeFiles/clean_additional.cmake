# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\appCS300FinalTask_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appCS300FinalTask_autogen.dir\\ParseCache.txt"
  "appCS300FinalTask_autogen"
  )
endif()
