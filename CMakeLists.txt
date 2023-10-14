cmake_minimum_required(VERSION 3.10)
project(p101_posix_xsi_examples
        VERSION 0.0.1
        DESCRIPTION ""
        LANGUAGES C)

message(STATUS "Compiler being used: ${CMAKE_C_COMPILER}")

add_subdirectory(dirent)
add_subdirectory(fmtmsg)
add_subdirectory(ftw)
add_subdirectory(grp)
add_subdirectory(libgen)
add_subdirectory(math)
add_subdirectory(ndbm)
add_subdirectory(pwd)
add_subdirectory(search)
add_subdirectory(signal)
add_subdirectory(stdlib)
add_subdirectory(string)
add_subdirectory(strings)
add_subdirectory(sys)
add_subdirectory(syslog)
add_subdirectory(time)
add_subdirectory(unistd)
add_subdirectory(utmpx)
add_subdirectory(wchar)
