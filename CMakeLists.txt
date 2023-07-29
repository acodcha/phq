cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# Define the global settings.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffast-math -O3 -Wall -Wno-return-type")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)

# Define the PhQ project and its options.
project(
  "PhQ"
  VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "C++ library of physical quantities, physical models, and units of measure for scientific computation."
  HOMEPAGE_URL "https://github.com/acodcha/physical-quantities"
)
option(
  TEST_PHQ_LIBRARY
  "Configure the PhQ library tests."
  OFF
)

# Define the PhQ library.
add_library(
  ${PROJECT_NAME}
  INTERFACE
)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Configure the PhQ library tests.
if(TEST_PHQ_LIBRARY)
  # Fetch the GoogleTest library.
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
  )

  # Do not override the parent project's compiler and linker settings on Windows.
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

  # Include the GoogleTest library and enable testing.
  FetchContent_MakeAvailable(googletest)
  include(GoogleTest)
  enable_testing()

  # Define the test executables.

  add_executable(acceleration ${PROJECT_SOURCE_DIR}/test/Acceleration.cpp)
  target_link_libraries(acceleration GTest::gtest_main)
  gtest_discover_tests(acceleration)

  add_executable(acceleration_magnitude ${PROJECT_SOURCE_DIR}/test/AccelerationMagnitude.cpp)
  target_link_libraries(acceleration_magnitude GTest::gtest_main)
  gtest_discover_tests(acceleration_magnitude)

  add_executable(angle ${PROJECT_SOURCE_DIR}/test/Angle.cpp)
  target_link_libraries(angle GTest::gtest_main)
  gtest_discover_tests(angle)

  add_executable(angular_acceleration_magnitude ${PROJECT_SOURCE_DIR}/test/AngularAccelerationMagnitude.cpp)
  target_link_libraries(angular_acceleration_magnitude GTest::gtest_main)
  gtest_discover_tests(angular_acceleration_magnitude)

  add_executable(angular_speed ${PROJECT_SOURCE_DIR}/test/AngularSpeed.cpp)
  target_link_libraries(angular_speed GTest::gtest_main)
  gtest_discover_tests(angular_speed)

  add_executable(area ${PROJECT_SOURCE_DIR}/test/Area.cpp)
  target_link_libraries(area GTest::gtest_main)
  gtest_discover_tests(area)

  add_executable(area_vector ${PROJECT_SOURCE_DIR}/test/AreaVector.cpp)
  target_link_libraries(area_vector GTest::gtest_main)
  gtest_discover_tests(area_vector)

  add_executable(base_constants ${PROJECT_SOURCE_DIR}/test/Base/Constants.cpp)
  target_link_libraries(base_constants GTest::gtest_main)
  gtest_discover_tests(base_constants)

  add_executable(base_square_root ${PROJECT_SOURCE_DIR}/test/Base/SquareRoot.cpp)
  target_link_libraries(base_square_root GTest::gtest_main)
  gtest_discover_tests(base_square_root)

  add_executable(base_string ${PROJECT_SOURCE_DIR}/test/Base/String.cpp)
  target_link_libraries(base_string GTest::gtest_main)
  gtest_discover_tests(base_string)

  add_executable(bulk_dynamic_viscosity ${PROJECT_SOURCE_DIR}/test/BulkDynamicViscosity.cpp)
  target_link_libraries(bulk_dynamic_viscosity GTest::gtest_main)
  gtest_discover_tests(bulk_dynamic_viscosity)

  add_executable(constitutive_model_compressible_newtonian_fluid ${PROJECT_SOURCE_DIR}/test/ConstitutiveModel/CompressibleNewtonianFluid.cpp)
  target_link_libraries(constitutive_model_compressible_newtonian_fluid GTest::gtest_main)
  gtest_discover_tests(constitutive_model_compressible_newtonian_fluid)

  add_executable(constitutive_model_elastic_isotropic_solid ${PROJECT_SOURCE_DIR}/test/ConstitutiveModel/ElasticIsotropicSolid.cpp)
  target_link_libraries(constitutive_model_elastic_isotropic_solid GTest::gtest_main)
  gtest_discover_tests(constitutive_model_elastic_isotropic_solid)

  add_executable(constitutive_model_incompressible_newtonian_fluid ${PROJECT_SOURCE_DIR}/test/ConstitutiveModel/IncompressibleNewtonianFluid.cpp)
  target_link_libraries(constitutive_model_incompressible_newtonian_fluid GTest::gtest_main)
  gtest_discover_tests(constitutive_model_incompressible_newtonian_fluid)

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

  add_executable(displacement ${PROJECT_SOURCE_DIR}/test/Displacement.cpp)
  target_link_libraries(displacement GTest::gtest_main)
  gtest_discover_tests(displacement)

  add_executable(dynamic_viscosity ${PROJECT_SOURCE_DIR}/test/DynamicViscosity.cpp)
  target_link_libraries(dynamic_viscosity GTest::gtest_main)
  gtest_discover_tests(dynamic_viscosity)

  add_executable(frequency ${PROJECT_SOURCE_DIR}/test/Frequency.cpp)
  target_link_libraries(frequency GTest::gtest_main)
  gtest_discover_tests(frequency)

  add_executable(kinematic_viscosity ${PROJECT_SOURCE_DIR}/test/KinematicViscosity.cpp)
  target_link_libraries(kinematic_viscosity GTest::gtest_main)
  gtest_discover_tests(kinematic_viscosity)

  add_executable(length ${PROJECT_SOURCE_DIR}/test/Length.cpp)
  target_link_libraries(length GTest::gtest_main)
  gtest_discover_tests(length)

  add_executable(mach_number ${PROJECT_SOURCE_DIR}/test/MachNumber.cpp)
  target_link_libraries(mach_number GTest::gtest_main)
  gtest_discover_tests(mach_number)

  add_executable(mass ${PROJECT_SOURCE_DIR}/test/Mass.cpp)
  target_link_libraries(mass GTest::gtest_main)
  gtest_discover_tests(mass)

  add_executable(mass_density ${PROJECT_SOURCE_DIR}/test/MassDensity.cpp)
  target_link_libraries(mass_density GTest::gtest_main)
  gtest_discover_tests(mass_density)

  add_executable(mass_rate ${PROJECT_SOURCE_DIR}/test/MassRate.cpp)
  target_link_libraries(mass_rate GTest::gtest_main)
  gtest_discover_tests(mass_rate)

  add_executable(position ${PROJECT_SOURCE_DIR}/test/Position.cpp)
  target_link_libraries(position GTest::gtest_main)
  gtest_discover_tests(position)

  add_executable(sound_speed ${PROJECT_SOURCE_DIR}/test/SoundSpeed.cpp)
  target_link_libraries(sound_speed GTest::gtest_main)
  gtest_discover_tests(sound_speed)

  add_executable(speed ${PROJECT_SOURCE_DIR}/test/Speed.cpp)
  target_link_libraries(speed GTest::gtest_main)
  gtest_discover_tests(speed)

  add_executable(time ${PROJECT_SOURCE_DIR}/test/Time.cpp)
  target_link_libraries(time GTest::gtest_main)
  gtest_discover_tests(time)

  add_executable(transport_energy_consumption ${PROJECT_SOURCE_DIR}/test/TransportEnergyConsumption.cpp)
  target_link_libraries(transport_energy_consumption GTest::gtest_main)
  gtest_discover_tests(transport_energy_consumption)

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

  add_executable(unit_dimensionless ${PROJECT_SOURCE_DIR}/test/Unit/Dimensionless.cpp)
  target_link_libraries(unit_dimensionless GTest::gtest_main)
  gtest_discover_tests(unit_dimensionless)

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

  add_executable(unit_specific_power ${PROJECT_SOURCE_DIR}/test/Unit/SpecificPower.cpp)
  target_link_libraries(unit_specific_power GTest::gtest_main)
  gtest_discover_tests(unit_specific_power)

  add_executable(unit_speed ${PROJECT_SOURCE_DIR}/test/Unit/Speed.cpp)
  target_link_libraries(unit_speed GTest::gtest_main)
  gtest_discover_tests(unit_speed)

  add_executable(unit_system ${PROJECT_SOURCE_DIR}/test/UnitSystem.cpp)
  target_link_libraries(unit_system GTest::gtest_main)
  gtest_discover_tests(unit_system)

  add_executable(unit_temperature ${PROJECT_SOURCE_DIR}/test/Unit/Temperature.cpp)
  target_link_libraries(unit_temperature GTest::gtest_main)
  gtest_discover_tests(unit_temperature)

  add_executable(unit_temperature_difference ${PROJECT_SOURCE_DIR}/test/Unit/TemperatureDifference.cpp)
  target_link_libraries(unit_temperature_difference GTest::gtest_main)
  gtest_discover_tests(unit_temperature_difference)

  add_executable(unit_temperature_gradient ${PROJECT_SOURCE_DIR}/test/Unit/TemperatureGradient.cpp)
  target_link_libraries(unit_temperature_gradient GTest::gtest_main)
  gtest_discover_tests(unit_temperature_gradient)

  add_executable(unit_thermal_conductivity ${PROJECT_SOURCE_DIR}/test/Unit/ThermalConductivity.cpp)
  target_link_libraries(unit_thermal_conductivity GTest::gtest_main)
  gtest_discover_tests(unit_thermal_conductivity)

  add_executable(unit_thermal_expansion ${PROJECT_SOURCE_DIR}/test/Unit/ThermalExpansion.cpp)
  target_link_libraries(unit_thermal_expansion GTest::gtest_main)
  gtest_discover_tests(unit_thermal_expansion)

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

  add_executable(velocity ${PROJECT_SOURCE_DIR}/test/Velocity.cpp)
  target_link_libraries(velocity GTest::gtest_main)
  gtest_discover_tests(velocity)

  add_executable(volume ${PROJECT_SOURCE_DIR}/test/Volume.cpp)
  target_link_libraries(volume GTest::gtest_main)
  gtest_discover_tests(volume)

  add_executable(volume_rate ${PROJECT_SOURCE_DIR}/test/VolumeRate.cpp)
  target_link_libraries(volume_rate GTest::gtest_main)
  gtest_discover_tests(volume_rate)

  message(STATUS "The PhQ library tests were configured. Build the PhQ library tests with \"make --jobs=16\" and run them with \"make test\"")
else()
  message(STATUS "The PhQ library tests were not configured. Run \"cmake .. -DTEST_PHQ_LIBRARY=ON\" to configure the PhQ library tests.")
endif()

# Define the library directories to be installed.
include(GNUInstallDirs)
install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Write the installation configuration files.
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "PhQConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)
file(
  WRITE "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake.input"
  "@PACKAGE_INIT@\ninclude(\"${CMAKE_CURRENT_LIST_DIR}/@PROJECT_NAME@Targets.cmake\")\ncheck_required_components(\"@PROJECT_NAME@\")\n"
)
configure_package_config_file(
  "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake.input"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)

# Define the installation instructions.
install(
  EXPORT ${PROJECT_NAME}_Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)
install(
  FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
)
install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/include/PhQ
  DESTINATION include
)
