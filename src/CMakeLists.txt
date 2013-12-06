include_directories(${COMMON_INCLUDES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

SET(
	CORE_SOURCES
	adapter.cpp
	adapter_yaml.cpp
	antenna.cpp
	antenna_yaml.cpp
	broadcasttype.cpp
	broadcasttype_yaml.cpp
	channel.cpp
	channel_yaml.cpp
	configuration.cpp
	ipsubnet.cpp
	modulation.cpp
	modulation_yaml.cpp
	multiplex.cpp
	multiplex_yaml.cpp
#	multiplexsat.cpp
#	multiplexsat_yaml.cpp
#	multiplextnt.cpp
#	multiplextnt_yaml.cpp
#	polarization.cpp
#	polarzation_yaml.cpp
)

add_library(core OBJECT ${CORE_SOURCES})
add_library(dvblmgr_shared SHARED $<TARGET_OBJECTS:core>)
set_target_properties(dvblmgr_shared PROPERTIES OUTPUT_NAME dvblmgr)
if(YAMLCPP_STATIC_LIBRARY)
    target_link_libraries(dvblmgr_shared ${YAMLCPP_LIBRARY})
endif()
add_library(dvblmgr_static STATIC $<TARGET_OBJECTS:core>)
set_target_properties(dvblmgr_static PROPERTIES OUTPUT_NAME dvblmgr)

add_executable(dvblmgr dvblmgr.cpp)
target_link_libraries(dvblmgr dvblmgr_shared ${YAMLCPP_LIBRARY})
add_executable(dvbld dvbld.cpp)
target_link_libraries(dvbld dvblmgr_shared ${YAMLCPP_LIBRARY})
