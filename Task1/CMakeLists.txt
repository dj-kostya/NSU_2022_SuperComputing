cmake_minimum_required(VERSION 3.22)
project(Task1)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

find_library(zmq_location NAMES libminirt.a)
set(CMAKE_CXX_STANDARD 11)

message(STATUS ${zmq_location})

add_library(zmq STATIC IMPORTED)
add_executable(Task1 minirt_test_openmp.cpp)
TARGET_LINK_LIBRARIES(Task1 PUBLIC minirt)


