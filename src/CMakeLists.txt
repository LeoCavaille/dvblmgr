include_directories(${COMMON_INCLUDES})

file(GLOB SOURCES *.cpp)
list(REMOVE_ITEM SOURCES dvblmgr.cpp dvbld.cpp)

add_library(core OBJECT ${SOURCES})
add_library(dvblmgr_shared STATIC $<TARGET_OBJECTS:core>)
add_library(dvblmgr_static SHARED $<TARGET_OBJECTS:core>)
