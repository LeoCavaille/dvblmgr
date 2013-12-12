project(dvblmgr)

set(CMAKE_CXX_FLAGS "-std=c++11 ")
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -pedantic -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# The public .h files of libdvblmgr
include_directories(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/../libdvblmgr/include)

# The .cpp implementation files
file(GLOB_RECURSE DVBLMGR_SOURCES ${PROJECT_SOURCE_DIR}/src/ *.cpp)

find_package(Threads)

add_executable(dvblmgr_binary ${DVBLMGR_SOURCES})
set_target_properties(dvblmgr_binary PROPERTIES OUTPUT_NAME dvblmgr)

# Link with yaml-cpp
target_link_libraries(dvblmgr_binary ${YAMLCPP_LIBRARY})
# Link with -pthread
target_link_libraries(dvblmgr_binary ${CMAKE_THREAD_LIBS_INIT})
# Link with our shared libdvblmgr
target_link_libraries(dvblmgr_binary libdvblmgr)
