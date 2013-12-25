project(libdvblmgr)

set(CMAKE_CXX_FLAGS "-std=c++11 ")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -pedantic -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

###########
# Dependencies
###########
# Find yaml-cpp library
include( ${PROJECT_SOURCE_DIR}/FindYamlCMakeLists.txt )


# The public .h files of libdvblmgr
include_directories(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

# The .cpp implementation files
set (
	LIB_SOURCES
	src/adapter.cpp
	src/antenna.cpp
	src/broadcasttype.cpp
	src/channel.cpp
	src/ipsubnet.cpp
	src/machine.cpp
	src/modulation.cpp
	src/multiplex.cpp
	src/multiplexsat.cpp
	src/multiplextnt.cpp
	src/polarization.cpp
	src/yaml/adapter.cpp
	src/yaml/antenna.cpp
	src/yaml/broadcasttype.cpp
	src/yaml/channel.cpp
	src/yaml/machine.cpp
	src/yaml/modulation.cpp
	src/yaml/multiplex.cpp
	src/yaml/multiplexsat.cpp
	src/yaml/multiplextnt.cpp
	src/yaml/polarization.cpp
)

add_library(libdvblmgr_objects OBJECT ${LIB_SOURCES})
add_library(dvblmgr_shared SHARED $<TARGET_OBJECTS:libdvblmgr_objects>)

set_target_properties(dvblmgr_shared PROPERTIES OUTPUT_NAME dvblmgr)
if(YAMLCPP_STATIC_LIBRARY)
    target_link_libraries(dvblmgr_shared ${YAMLCPP_LIBRARY})
endif()
add_library(dvblmgr_static STATIC $<TARGET_OBJECTS:libdvblmgr_objects>)
set_target_properties(dvblmgr_static PROPERTIES OUTPUT_NAME dvblmgr)


##############
# Testing
##############

# The .cpp test files
set(
	TEST_UNITS_SOURCES
	test/test_adapter.cpp
	test/test_antenna.cpp
	test/test_broadcasttype.cpp
	test/test_channel.cpp
	test/test_ipsubnet.cpp
	test/test_machine.cpp
	test/test_multiplex.cpp
	test/test_polarization.cpp
)

add_executable(runTestsLibrary ${TEST_UNITS_SOURCES} test/main.cpp)
# Standard linking to gtest stuff.
target_link_libraries(runTestsLibrary gtest gtest_main)
# Extra linking for the project.
target_link_libraries(runTestsLibrary dvblmgr_shared ${YAMLCPP_LIBRARY})
# Create a symlink to the build directory
if(NOT EXISTS ${CMAKE_BINARY_DIR}/yaml)
ADD_CUSTOM_COMMAND( TARGET runTestsLibrary
					POST_BUILD
                    COMMAND ln -s ${PROJECT_SOURCE_DIR}/../yaml ${CMAKE_BINARY_DIR}/yaml
                    COMMENT "Generating symbolic link in test folder for yaml fixtures")
endif()