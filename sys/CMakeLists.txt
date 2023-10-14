cmake_minimum_required(VERSION 3.10)
project(p101_posix_xsi_examples
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES C)

message(STATUS "Compiler being used: ${CMAKE_C_COMPILER}")

add_subdirectory(ipc)
add_subdirectory(mman)
add_subdirectory(msg)
add_subdirectory(resource)
add_subdirectory(shm)
add_subdirectory(stat)
add_subdirectory(time)
add_subdirectory(uio)
