include_directories(${COMMON_INCLUDES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

SET(
	CORE_SOURCES
	adapter.cpp
	antenna.cpp
	channel.cpp
	configuration.cpp
	ipsubnet.cpp
	modulation.cpp
	multiplex.cpp
)

add_library(core OBJECT ${CORE_SOURCES})
add_library(dvblmgr_shared SHARED $<TARGET_OBJECTS:core>)
set_target_properties(dvblmgr_shared PROPERTIES OUTPUT_NAME dvblmgr)
add_library(dvblmgr_static STATIC $<TARGET_OBJECTS:core>)
set_target_properties(dvblmgr_static PROPERTIES OUTPUT_NAME dvblmgr)

add_executable(dvblmgr dvblmgr.cpp)
target_link_libraries(dvblmgr dvblmgr_shared yaml-cpp)
add_executable(dvbld dvbld.cpp)
target_link_libraries(dvbld dvblmgr_shared yaml-cpp)