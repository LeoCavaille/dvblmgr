include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

file(
    GLOB
    ProtoFiles
    *.proto
)

PROTOBUF_GENERATE_CPP(PROTOBUF_SRCS PROTOBUF_HDRS ${ProtoFiles})

add_library(libdvblmgrprotobuf STATIC ${PROTOBUF_SRCS})
target_link_libraries(libdvblmgrprotobuf ${PROTOBUF_LIBRARY})
