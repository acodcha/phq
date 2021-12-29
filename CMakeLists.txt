cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

################################################################################
# Project
################################################################################

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math -O3 -Wall -Wno-return-type")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project(
  "PhQ" VERSION 1.0.1 LANGUAGES CXX
  DESCRIPTION "C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation."
  HOMEPAGE_URL "https://github.com/acodcha/physical-quantities"
)

option(BUILD_DOCS "Build documentation using Doxygen." OFF)
option(BUILD_TESTING "Build testing executables." OFF)

include(CMakePackageConfigHelpers)
include(CTest)
include(GNUInstallDirs)

set(PHQ_INCLUDE_BUILD_DIR "${PROJECT_SOURCE_DIR}/include/")
add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

target_include_directories(
  ${PROJECT_NAME} INTERFACE
  $<BUILD_INTERFACE:${PHQ_INCLUDE_BUILD_DIR}>
  $<INSTALL_INTERFACE:include>
)

################################################################################
# Documentation
################################################################################

if(BUILD_DOCS)
  find_package(Doxygen REQUIRED dot)
  if(NOT Doxygen_FOUND)
    message(WARNING "Cannot generate documentation because Doxygen is not installed. Install it with \"sudo apt install doxygen graphviz texlive\".")
    return()
  endif()
  add_custom_target(
    docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/docs
    COMMENT "Generating documentation with Doxygen..."
    VERBATIM)
endif()

################################################################################
# Testing
################################################################################

if(BUILD_TESTING)
  enable_testing()

  add_executable(constitutive-models test/ConstitutiveModels.cpp)
  target_link_libraries(constitutive-models)
  add_test(NAME ConstitutiveModels COMMAND bin/constitutive-models)

  add_executable(conversions test/Conversions.cpp)
  target_link_libraries(conversions)
  add_test(NAME Conversions COMMAND bin/conversions)

  add_executable(dimensions ${PROJECT_SOURCE_DIR}/test/Dimensions.cpp)
  target_link_libraries(dimensions)
  add_test(NAME Dimensions COMMAND bin/dimensions)

  add_executable(relations test/Relations.cpp)
  target_link_libraries(relations)
  add_test(NAME Relations COMMAND bin/relations)

  add_executable(thermodynamic-state-models test/ThermodynamicStateModels.cpp)
  target_link_libraries(thermodynamic-state-models)
  add_test(NAME ThermodynamicStateModels COMMAND bin/thermodynamic-state-models)

  message(STATUS "Testing was configured. Build the testing executables with \"make -j\" and run them with \"make test\"")
else()
  message(STATUS "Testing was not configured. Run \"cmake .. -DBUILD_TESTING=ON\" to configure testing.")
endif()

################################################################################
# Installation
################################################################################

install(
  TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

write_basic_package_version_file(
  "${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION} COMPATIBILITY AnyNewerVersion)

file(
  WRITE "${PROJECT_BINARY_DIR}/Config.cmake.input"
  "@PACKAGE_INIT@\ninclude(\"${CMAKE_CURRENT_LIST_DIR}/@PROJECT_NAME@Targets.cmake\")\ncheck_required_components(\"@PROJECT_NAME@\")\n"
)

configure_package_config_file(
  "${PROJECT_BINARY_DIR}/Config.cmake.input"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
  EXPORT ${PROJECT_NAME}_Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
  FILES
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

install(
  DIRECTORY ${PHQ_INCLUDE_BUILD_DIR}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

message(STATUS "Installation was configured. Install to ${CMAKE_INSTALL_INCLUDEDIR} and ${CMAKE_INSTALL_DATAROOTDIR} with \"sudo make install\".")
