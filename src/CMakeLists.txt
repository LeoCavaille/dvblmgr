include_directories(${COMMON_INCLUDES} ${PROJECT_SOURCE_DIR}/include)

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
    configuration.cpp # FIXME
    confobject.cpp
    ipsubnet.cpp
    machine.cpp
    machine_yaml.cpp
    modulation.cpp
    modulation_yaml.cpp
    multiplex.cpp
    multiplex_yaml.cpp
    multiplextnt.cpp
    multiplextnt_yaml.cpp
    multiplexsat.cpp
    multiplexsat_yaml.cpp
    polarization.cpp
    polarization_yaml.cpp
)

add_library(core OBJECT ${CORE_SOURCES})
add_library(dvblmgr_shared SHARED $<TARGET_OBJECTS:core>)
set_target_properties(dvblmgr_shared PROPERTIES OUTPUT_NAME dvblmgr)
if(YAMLCPP_STATIC_LIBRARY)
    target_link_libraries(dvblmgr_shared ${YAMLCPP_LIBRARY})
endif()
add_library(dvblmgr_static STATIC $<TARGET_OBJECTS:core>)
set_target_properties(dvblmgr_static PROPERTIES OUTPUT_NAME dvblmgr)

find_package( Threads )


SET(
    DVBLMGR_SOURCES
    broadcastlistgenerator.cpp
    commands/adapterstart.cpp
    commands/heartbeat.cpp
    command.cpp
    commanddispatcher.cpp
    serverrunner.cpp
    watchdog.cpp
)

add_executable(dvblmgr dvblmgr.cpp ${DVBLMGR_SOURCES} ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(dvblmgr dvblmgr_shared ${YAMLCPP_LIBRARY} ${PROTOBUF_LIBRARIES})
target_link_libraries( dvblmgr ${CMAKE_THREAD_LIBS_INIT} )

add_executable(dvbld dvbld.cpp)
target_link_libraries(dvbld dvblmgr_shared ${YAMLCPP_LIBRARY})
