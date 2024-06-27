add_library(Search Search.hpp Search.cpp)
include_directories(${Protobuf_INCLUDE_DIRS} ${absl_INCLUDE_DIRS})
target_link_libraries(Search ${Protobuf_LIBRARIES} ${protobuf_ABSL_USED_TARGETS})
