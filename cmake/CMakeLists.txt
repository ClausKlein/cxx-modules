cmake_minimum_required(VERSION 3.28.4...3.30)

project(cpp20-modules VERSION 0.1.0 LANGUAGES CXX)

# make sure c++20 is set
set(CMAKE_CXX_STANDARD 20) # turn on the dynamic depends for ninja
set(CMAKE_CXX_EXTENSIONS NO)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_SCAN_FOR_MODULES YES)

# # The dynamic experiment is Over!
# if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
#   include(cmake/clang_modules.cmake)
# elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#   include(cmake/gcc_modules.cmake)
# endif()

find_package(idc ${cpp20-modules_VERSION} QUIET)

if(idc_FOUND)
  set(CMAKE_SKIP_INSTALL_RULES TRUE)
  add_idc_module(idc)
else()
  add_library(idc)
  add_library(idc::idc ALIAS idc)
  target_compile_features(idc PUBLIC cxx_std_20)

  # cmake-format: off
  target_sources(idc
    PUBLIC
      FILE_SET cxx_modules
      TYPE CXX_MODULES
      FILES
          idc.cppm
          helper.cppm
  )
  # cmake-format: on
endif()

add_executable(main main.cpp)
target_link_libraries(main idc)

enable_testing()
add_test(NAME test COMMAND main)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

if(NOT CMAKE_SKIP_INSTALL_RULES)
  set(IDC_CMAKE_DIR ${CMAKE_INSTALL_LIBDIR}/cmake/idc) # CACHE STRING
  # "Installation directory for cmake files, a relative path that "
  # "will be joined with ${CMAKE_INSTALL_PREFIX} or an absolute "
  # "path.")
  set(version_config ${PROJECT_BINARY_DIR}/idc-config-version.cmake)
  set(project_config ${PROJECT_BINARY_DIR}/idc-config.cmake)
  set(targets_export_name idc-targets)

  configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/idc-config.cmake.in ${project_config} INSTALL_DESTINATION ${IDC_CMAKE_DIR}
  )

  # Generate the version, config and target files into the build directory.
  write_basic_package_version_file(${version_config} VERSION ${cpp20-modules_VERSION} COMPATIBILITY AnyNewerVersion)

  install(TARGETS main idc EXPORT ${targets_export_name} FILE_SET cxx_modules
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/idc/modules
  )

  # Use a namespace because CMake provides better diagnostics for namespaced imported targets.
  export(TARGETS ${INSTALL_TARGETS} NAMESPACE idc:: FILE ${PROJECT_BINARY_DIR}/${targets_export_name}.cmake)

  # Install version, config and target files.
  install(FILES ${project_config} ${version_config} DESTINATION ${IDC_CMAKE_DIR})
  install(EXPORT ${targets_export_name} DESTINATION ${IDC_CMAKE_DIR} NAMESPACE idc::)
endif()
