cmake_minimum_required(VERSION 2.6)
project(recipes CXX)

#set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_COMPILER "g++")
set(cxx_flags -D_FILE_OFFSET_BITS=64 -O2 -g -Wall -Werror -std=c++0x)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${cxx_flags}")
message(STATUS "cxx_flags = " ${CMAKE_CXX_FLAGS})


include_directories(${CMAKE_CURRENT_LIST_DIR}/3rd/googletest/include)
link_directories(${CMAKE_CURRENT_LIST_DIR}/3rd/googletest/lib)

add_subdirectory(test)

