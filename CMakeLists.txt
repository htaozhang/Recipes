cmake_minimum_required(VERSION 2.6)
project(recipes CXX)

#set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_CXX_COMPILER "g++")
set(cxx_flags -D_FILE_OFFSET_BITS=64 -O2 -g -Wall -Werror -std=c++0x)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${cxx_flags}")
message(STATUS "cxx_flags = " ${CMAKE_CXX_FLAGS})


option(ENABLE_TESTING "Enable smoke tests" OFF)

if (ENABLE_TESTING)
    enable_testing()

    set(BUILD_GTEST ON)
    set(BUILD_GMOCK OFF)
    set(BUILD_SHARED_LIBS OFF)

    mark_as_advanced(BUILD_GMOCK)
    mark_as_advanced(BUILD_GTEST)
    mark_as_advanced(gmock_build_tests)
    mark_as_advanced(gtest_build_samples)
    mark_as_advanced(gtest_build_tests)
    mark_as_advanced(gtest_disable_pthreads)
    mark_as_advanced(gtest_force_shared_crt)
    mark_as_advanced(gtest_hide_internal_symbols)

    add_subdirectory(third-party/googletest)
    add_subdirectory(test)
endif (ENABLE_TESTING)




