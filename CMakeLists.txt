cmake_minimum_required(VERSION 3.25.0)
project(cpp20-modules VERSION 0.1.0)

# make sure c++ 20 is set
set(CMAKE_CXX_STANDARD 20)# turn on the dynamic depends for ninja
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
# turn on the experimental API
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API  "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  include(cmake/clang_modules.cmake)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  include(cmake/gcc_modules.cmake)
endif()


add_executable(idc)

target_sources(idc
  PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES
    idc.cppm
 PUBLIC
    main.cpp
)

