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
file(GLOB_RECURSE LIB_SOURCES ${PROJECT_SOURCE_DIR}/src/ *.cpp)

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
file(GLOB test_units_library ${PROJECT_SOURCE_DIR}/test/ test_*.cpp)

add_executable(runTests ${test_units_library} test/main.cpp)
# Standard linking to gtest stuff.
target_link_libraries(runTests gtest gtest_main)
# Extra linking for the project.
target_link_libraries(runTests libdvblmgr ${YAMLCPP_LIBRARY})
# Create a symlink to the build directory
ADD_CUSTOM_COMMAND( TARGET runTests
					POST_BUILD
                    COMMAND ln -s ${PROJECT_SOURCE_DIR}/../yaml ${CMAKE_BINARY_DIR}/yaml
                    COMMENT "Generating symbolic link in test folder for yaml fixtures")
