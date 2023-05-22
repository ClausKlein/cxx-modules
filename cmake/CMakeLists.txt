cmake_minimum_required(VERSION 3.26)
project(cpp20-modules VERSION 0.1.0 LANGUAGES CXX)

# make sure c++ 20 is set
set(CMAKE_CXX_STANDARD 20)# turn on the dynamic depends for ninja
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_CXX_SCAN_FOR_MODULES YES)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)

# turn on the experimental API
# this key to enable the feature changes with each cmake version
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API  "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

# the dynamic de
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  include(cmake/clang_modules.cmake)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  include(cmake/gcc_modules.cmake)
endif()


add_library(idc)
target_sources(idc
  #FIXME: PRIVATE idc.cpp
  PUBLIC
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    idc.cppm
    helper.cppm
)

add_executable(main main.cpp)
target_link_libraries(main idc)

