# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appeko_dashboard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appeko_dashboard_autogen.dir\\ParseCache.txt"
  "appeko_dashboard_autogen"
  )
endif()
