cmake_minimum_required(VERSION 3.21)
project(p101_posix_xsi_examples
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES C)

add_subdirectory(ipc)
add_subdirectory(mman)
add_subdirectory(msg)
add_subdirectory(resource)
add_subdirectory(shm)
add_subdirectory(stat)
add_subdirectory(time)
add_subdirectory(uio)
