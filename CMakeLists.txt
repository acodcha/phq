cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -ffast-math -O3 -Wall -Wno-return-type")

project(PhysicalQuantities CXX)

file(GLOB_RECURSE source_files test/*.cpp)

add_executable(test_all ${source_files})
target_link_libraries(test_all)

