cmake_minimum_required(VERSION 2.8)

project(dvblmgr)

include(${CMAKE_CURRENT_SOURCE_DIR}/FindYamlCMakeLists.txt)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -std=c++11 -O0")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include ${YAMLCPP_INCLUDE_DIR})
add_subdirectory(src)

##############
# Testing
##############
# This adds another subdirectory, which has 'project(gtest)'.
add_subdirectory(lib/gtest-1.7.0)
enable_testing()

# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Retrieve test files
file(
	GLOB
	test_units
	test/*.cpp
)

include_directories(${COMMON_INCLUDES})
include_directories(src/)
add_executable(runTests ${test_units} test/main.cpp)

# Standard linking to gtest stuff.
target_link_libraries(runTests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(runTests dvblmgr_shared ${YAMLCPP_LIBRARY})

# Copy our fixtures to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/test/yaml DESTINATION ${CMAKE_BINARY_DIR})
