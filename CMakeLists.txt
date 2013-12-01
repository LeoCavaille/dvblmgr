cmake_minimum_required(VERSION 2.8)

project(dvblmgr)

set(CMAKE_CXX_FLAGS "-g -Wall -Wextra -pedantic -std=c++11")

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
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
	test/test_*
)

include_directories(${COMMON_INCLUDES})
add_executable(runTests ${test_units} test/main.cpp)

# Standard linking to gtest stuff.
target_link_libraries(runTests gtest gtest_main)

# Extra linking for the project.
target_link_libraries(runTests dvblmgr_shared)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(NAME that-test-I-made COMMAND runUnitTests)

# You can also omit NAME and COMMAND. The second argument could be some other
# test executable.
add_test(that-other-test-I-made runUnitTests)
