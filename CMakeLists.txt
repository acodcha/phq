cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

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
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
  )

  # Do not override the parent project's compiler and linker settings on Windows.
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  FetchContent_MakeAvailable(googletest)

  include(GoogleTest)

  enable_testing()

  # With GoogleTest, use gtest_discover_tests(my_test) instead of add_test(NAME my_test COMMAND bin/my_test)

  add_executable(base_constant ${PROJECT_SOURCE_DIR}/test/Base/Constant.cpp)
  target_link_libraries(base_constant GTest::gtest_main)
  gtest_discover_tests(base_constant)

  add_executable(base_string ${PROJECT_SOURCE_DIR}/test/Base/String.cpp)
  target_link_libraries(base_string GTest::gtest_main)
  gtest_discover_tests(base_string)

  add_executable(dimension_electric_current ${PROJECT_SOURCE_DIR}/test/Dimension/ElectricCurrent.cpp)
  target_link_libraries(dimension_electric_current GTest::gtest_main)
  gtest_discover_tests(dimension_electric_current)

  add_executable(dimension_length ${PROJECT_SOURCE_DIR}/test/Dimension/Length.cpp)
  target_link_libraries(dimension_length GTest::gtest_main)
  gtest_discover_tests(dimension_length)

  add_executable(dimension_luminous_intensity ${PROJECT_SOURCE_DIR}/test/Dimension/LuminousIntensity.cpp)
  target_link_libraries(dimension_luminous_intensity GTest::gtest_main)
  gtest_discover_tests(dimension_luminous_intensity)

  add_executable(dimension_mass ${PROJECT_SOURCE_DIR}/test/Dimension/Mass.cpp)
  target_link_libraries(dimension_mass GTest::gtest_main)
  gtest_discover_tests(dimension_mass)

  add_executable(dimension_set ${PROJECT_SOURCE_DIR}/test/Dimension/Set.cpp)
  target_link_libraries(dimension_set GTest::gtest_main)
  gtest_discover_tests(dimension_set)

  add_executable(dimension_substance_amount ${PROJECT_SOURCE_DIR}/test/Dimension/SubstanceAmount.cpp)
  target_link_libraries(dimension_substance_amount GTest::gtest_main)
  gtest_discover_tests(dimension_substance_amount)

  add_executable(dimension_temperature ${PROJECT_SOURCE_DIR}/test/Dimension/Temperature.cpp)
  target_link_libraries(dimension_temperature GTest::gtest_main)
  gtest_discover_tests(dimension_temperature)

  add_executable(dimension_time ${PROJECT_SOURCE_DIR}/test/Dimension/Time.cpp)
  target_link_libraries(dimension_time GTest::gtest_main)
  gtest_discover_tests(dimension_time)

  add_executable(direction ${PROJECT_SOURCE_DIR}/test/Direction.cpp)
  target_link_libraries(direction GTest::gtest_main)
  gtest_discover_tests(direction)

  add_executable(unit_acceleration ${PROJECT_SOURCE_DIR}/test/Unit/Acceleration.cpp)
  target_link_libraries(unit_acceleration GTest::gtest_main)
  gtest_discover_tests(unit_acceleration)

  add_executable(unit_angle ${PROJECT_SOURCE_DIR}/test/Unit/Angle.cpp)
  target_link_libraries(unit_angle GTest::gtest_main)
  gtest_discover_tests(unit_angle)

  add_executable(unit_angular_acceleration ${PROJECT_SOURCE_DIR}/test/Unit/AngularAcceleration.cpp)
  target_link_libraries(unit_angular_acceleration GTest::gtest_main)
  gtest_discover_tests(unit_angular_acceleration)

  add_executable(unit_angular_speed ${PROJECT_SOURCE_DIR}/test/Unit/AngularSpeed.cpp)
  target_link_libraries(unit_angular_speed GTest::gtest_main)
  gtest_discover_tests(unit_angular_speed)

  add_executable(unit_area ${PROJECT_SOURCE_DIR}/test/Unit/Area.cpp)
  target_link_libraries(unit_area GTest::gtest_main)
  gtest_discover_tests(unit_area)

  add_executable(unit_diffusivity ${PROJECT_SOURCE_DIR}/test/Unit/Diffusivity.cpp)
  target_link_libraries(unit_diffusivity GTest::gtest_main)
  gtest_discover_tests(unit_diffusivity)

  add_executable(unit_dynamic_viscosity ${PROJECT_SOURCE_DIR}/test/Unit/DynamicViscosity.cpp)
  target_link_libraries(unit_dynamic_viscosity GTest::gtest_main)
  gtest_discover_tests(unit_dynamic_viscosity)

  add_executable(unit_energy ${PROJECT_SOURCE_DIR}/test/Unit/Energy.cpp)
  target_link_libraries(unit_energy GTest::gtest_main)
  gtest_discover_tests(unit_energy)

  add_executable(unit_energy_flux ${PROJECT_SOURCE_DIR}/test/Unit/EnergyFlux.cpp)
  target_link_libraries(unit_energy_flux GTest::gtest_main)
  gtest_discover_tests(unit_energy_flux)

  add_executable(unit_force ${PROJECT_SOURCE_DIR}/test/Unit/Force.cpp)
  target_link_libraries(unit_force GTest::gtest_main)
  gtest_discover_tests(unit_force)

  add_executable(unit_frequency ${PROJECT_SOURCE_DIR}/test/Unit/Frequency.cpp)
  target_link_libraries(unit_frequency GTest::gtest_main)
  gtest_discover_tests(unit_frequency)

  add_executable(unit_heat_capacity ${PROJECT_SOURCE_DIR}/test/Unit/HeatCapacity.cpp)
  target_link_libraries(unit_heat_capacity GTest::gtest_main)
  gtest_discover_tests(unit_heat_capacity)

  add_executable(unit_length ${PROJECT_SOURCE_DIR}/test/Unit/Length.cpp)
  target_link_libraries(unit_length GTest::gtest_main)
  gtest_discover_tests(unit_length)

  add_executable(unit_mass ${PROJECT_SOURCE_DIR}/test/Unit/Mass.cpp)
  target_link_libraries(unit_mass GTest::gtest_main)
  gtest_discover_tests(unit_mass)

  add_executable(unit_mass_density ${PROJECT_SOURCE_DIR}/test/Unit/MassDensity.cpp)
  target_link_libraries(unit_mass_density GTest::gtest_main)
  gtest_discover_tests(unit_mass_density)

  add_executable(unit_mass_rate ${PROJECT_SOURCE_DIR}/test/Unit/MassRate.cpp)
  target_link_libraries(unit_mass_rate GTest::gtest_main)
  gtest_discover_tests(unit_mass_rate)

  add_executable(unit_memory ${PROJECT_SOURCE_DIR}/test/Unit/Memory.cpp)
  target_link_libraries(unit_memory GTest::gtest_main)
  gtest_discover_tests(unit_memory)

  add_executable(unit_memory_rate ${PROJECT_SOURCE_DIR}/test/Unit/MemoryRate.cpp)
  target_link_libraries(unit_memory_rate GTest::gtest_main)
  gtest_discover_tests(unit_memory_rate)

  add_executable(unit_power ${PROJECT_SOURCE_DIR}/test/Unit/Power.cpp)
  target_link_libraries(unit_power GTest::gtest_main)
  gtest_discover_tests(unit_power)

  add_executable(unit_pressure ${PROJECT_SOURCE_DIR}/test/Unit/Pressure.cpp)
  target_link_libraries(unit_pressure GTest::gtest_main)
  gtest_discover_tests(unit_pressure)

  add_executable(unit_specific_energy ${PROJECT_SOURCE_DIR}/test/Unit/SpecificEnergy.cpp)
  target_link_libraries(unit_specific_energy GTest::gtest_main)
  gtest_discover_tests(unit_specific_energy)

  add_executable(unit_specific_heat_capacity ${PROJECT_SOURCE_DIR}/test/Unit/SpecificHeatCapacity.cpp)
  target_link_libraries(unit_specific_heat_capacity GTest::gtest_main)
  gtest_discover_tests(unit_specific_heat_capacity)

  add_executable(unit_system ${PROJECT_SOURCE_DIR}/test/UnitSystem.cpp)
  target_link_libraries(unit_system GTest::gtest_main)
  gtest_discover_tests(unit_system)

  add_executable(unit_time ${PROJECT_SOURCE_DIR}/test/Unit/Time.cpp)
  target_link_libraries(unit_time GTest::gtest_main)
  gtest_discover_tests(unit_time)

  add_executable(unit_volume ${PROJECT_SOURCE_DIR}/test/Unit/Volume.cpp)
  target_link_libraries(unit_volume GTest::gtest_main)
  gtest_discover_tests(unit_volume)

  add_executable(unit_volume_rate ${PROJECT_SOURCE_DIR}/test/Unit/VolumeRate.cpp)
  target_link_libraries(unit_volume_rate GTest::gtest_main)
  gtest_discover_tests(unit_volume_rate)

  add_executable(value_dyad ${PROJECT_SOURCE_DIR}/test/Value/Dyad.cpp)
  target_link_libraries(value_dyad GTest::gtest_main)
  gtest_discover_tests(value_dyad)

  add_executable(value_symmetric_dyad ${PROJECT_SOURCE_DIR}/test/Value/SymmetricDyad.cpp)
  target_link_libraries(value_symmetric_dyad GTest::gtest_main)
  gtest_discover_tests(value_symmetric_dyad)

  add_executable(value_vector ${PROJECT_SOURCE_DIR}/test/Value/Vector.cpp)
  target_link_libraries(value_vector GTest::gtest_main)
  gtest_discover_tests(value_vector)

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
