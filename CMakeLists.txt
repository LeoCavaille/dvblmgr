cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -pedantic -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

project(dvblmgr-suite)

################
# Dependencies #
################

# Find yaml-cpp library
include( ${PROJECT_SOURCE_DIR}/FindYamlCMakeLists.txt )


# We use the googletest framework for our test test_units_library
add_subdirectory(lib/gtest-1.7.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${YAMLCPP_INCLUDE_DIR})

# Generate our protobuf classes
add_subdirectory(proto)

# Build the public shared libdvblmgr
add_subdirectory(libdvblmgr)

# Build the server binary dvblmgr
add_subdirectory(dvblmgr)
