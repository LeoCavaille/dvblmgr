project(dvblmgr)

set(CMAKE_CXX_FLAGS "-std=c++11 ")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -pedantic -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# The public .h files of libdvblmgr
include_directories(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/../libdvblmgr/include)

# The .cpp implementation files
add_library(
	dvblmgr_sources
	OBJECT
	src/broadcastlistgenerator.cpp
	src/command.cpp
	src/commanddispatcher.cpp
	src/commands/adapterstart.cpp
	src/commands/heartbeat.cpp
	src/configuration.cpp
	src/serverrunner.cpp
	src/watchdog.cpp
)

find_package(Threads)

# dvblmgr.cpp file is apart because it has the main() function
add_executable(dvblmgr_binary src/dvblmgr.cpp $<TARGET_OBJECTS:dvblmgr_sources>)
set_target_properties(dvblmgr_binary PROPERTIES OUTPUT_NAME dvblmgr)

# Link with yaml-cpp
target_link_libraries(dvblmgr_binary ${YAMLCPP_LIBRARY})
# Link with -pthread
target_link_libraries(dvblmgr_binary ${CMAKE_THREAD_LIBS_INIT})
# Link with our shared libdvblmgr
target_link_libraries(dvblmgr_binary dvblmgr_shared)


##############
# Testing
##############

include_directories(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/src)

# The .cpp test files
set(
	TEST_UNITS_SOURCES
	test/test_configuration.cpp
	test/test_broadcastlistgenerator.cpp
)

add_executable(runTestsDvblmgr ${TEST_UNITS_SOURCES} test/main.cpp $<TARGET_OBJECTS:dvblmgr_sources>)
# Standard linking to gtest stuff.
target_link_libraries(runTestsDvblmgr gtest gtest_main)
# Extra linking for the project.
target_link_libraries(runTestsDvblmgr dvblmgr_shared ${YAMLCPP_LIBRARY})
