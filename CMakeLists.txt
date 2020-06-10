cmake_minimum_required(VERSION 3.7 FATAL_ERROR)

##################################################
# C++ and build settings.
##################################################

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -ffast-math -O3 -Wall -Wno-return-type")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

##################################################
# Project definition.
##################################################

project(
  "PhQ"
  VERSION 0.1
  LANGUAGES CXX
  DESCRIPTION "C++17 header-only library of physical quantities, physical models, units of measure, and related concepts for scientific computation."
  HOMEPAGE_URL "https://github.com/acodcha/PhysicalQuantities")

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(CMakePackageConfigHelpers)
include(CPack)
include(CTest)
include(GNUInstallDirs)

option(PHQ_INSTALL "Install the PhQ library on the system." TRUE)
option(PHQ_TEST "Build tests." FALSE)
option(PHQ_DOCS "Generate documentation using Doxygen." TRUE)

target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)

##################################################
# Tests.
##################################################

if(BUILD_TESTING AND PHQ_TEST)

  enable_testing()

  add_executable(constitutive_models test/ConstitutiveModels.cpp)
  target_link_libraries(constitutive_models)
  add_test(NAME ConstitutiveModels COMMAND bin/constitutive_models)

  add_executable(conversions test/Conversions.cpp)
  target_link_libraries(conversions)
  add_test(NAME Conversions COMMAND bin/conversions)

  add_executable(dimensions ${PROJECT_SOURCE_DIR}/test/Dimensions.cpp)
  target_link_libraries(dimensions)
  add_test(NAME Dimensions COMMAND bin/dimensions)

  add_executable(relations test/Relations.cpp)
  target_link_libraries(relations)
  add_test(NAME Relations COMMAND bin/relations)

  add_executable(thermodynamic_state_models test/ThermodynamicStateModels.cpp)
  target_link_libraries(thermodynamic_state_models)
  add_test(NAME ThermodynamicStateModels COMMAND bin/thermodynamic_state_models)

endif()

##################################################
# Documentation.
##################################################

if(PHQ_DOCS)

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

##################################################
# Installation.
##################################################

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

write_basic_package_version_file(
  "${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

file(
  WRITE "${PROJECT_BINARY_DIR}/Config.cmake.input"
  "@PACKAGE_INIT@\ninclude(\"${CMAKE_CURRENT_LIST_DIR}/@PROJECT_NAME@Targets.cmake\")\ncheck_required_components(\"@PROJECT_NAME@\")\n")

configure_package_config_file(
  "${PROJECT_BINARY_DIR}/Config.cmake.input"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

if(PHQ_INSTALL)
  install(
    EXPORT ${PROJECT_NAME}_Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

  install(
    FILES
      "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
      "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

  install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/PhQ
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()

set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")

##################################################
# Messages.
##################################################

if(BUILD_TESTING AND PHQ_TEST)
  message(STATUS "Tests were configured. Build the tests with \"make -j\" and run them with \"make test\"")
else()
  message(STATUS "Tests were not configured. Run \"cmake .. -DPHQ_TEST=ON\" to configure the tests.")
endif()

if(PHQ_DOCS)
  message(STATUS "Documentation was configured. Generate the documentation with \"make docs\".")
else()
  message(STATUS "Documentation was not configured. Run \"cmake .. -DPHQ_DOCS=ON\" to configure the documentation.")
endif()

if(PHQ_INSTALL)
  message(STATUS "Installation was configured. Install to the system folder with \"sudo make install\".")
else()
  message(STATUS "Installation was not configured. Run \"cmake .. -DPHQ_INSTALL=ON\" to configure the installation.")
endif()

