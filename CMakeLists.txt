cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -ffast-math -O3 -Wall -Wno-return-type")

project(PhysicalQuantities CXX)

file(GLOB_RECURSE source_files *.cpp)

add_executable(dimensions test/Dimensions.cpp)
target_link_libraries(dimensions)

add_executable(conversions test/Conversions.cpp)
target_link_libraries(conversions)

add_executable(relations test/Relations.cpp)
target_link_libraries(relations)

add_executable(constitutive_models test/ConstitutiveModels.cpp)
target_link_libraries(constitutive_models)

add_executable(thermodynamic_state_models test/ThermodynamicStateModels.cpp)
target_link_libraries(thermodynamic_state_models)

