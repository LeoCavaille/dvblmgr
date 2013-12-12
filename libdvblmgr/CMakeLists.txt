project(libdvblmgr)

set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -pedantic -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

###########
# Dependencies
###########
# Find yaml-cpp library
include( ${PROJECT_SOURCE_DIR}/FindYamlCMakeLists.txt )
find_package( Threads )


# The public .h files of libdvblmgr
include_directories(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

# The .cpp implementation files
file(GLOB_RECURSE LIB_SOURCES ${PROJECT_SOURCE_DIR}/src *.cpp)

add_library(libobjects OBJECT ${LIB_SOURCES})
add_library(dvblmgr_shared SHARED $<TARGET_OBJECTS:libobjects>)

set_target_properties(dvblmgr_shared PROPERTIES OUTPUT_NAME dvblmgr)
if(YAMLCPP_STATIC_LIBRARY)
    target_link_libraries(dvblmgr_shared ${YAMLCPP_LIBRARY})
endif()
add_library(dvblmgr_static STATIC $<TARGET_OBJECTS:libobjects>)
set_target_properties(dvblmgr_static PROPERTIES OUTPUT_NAME dvblmgr)

