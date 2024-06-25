add_library(Index Index.hpp Index.cpp)

include_directories(${Protobuf_INCLUDE_DIRS} ${absl_INCLUDE_DIRS})
target_link_libraries(Index ${Protobuf_LIBRARIES} ${protobuf_ABSL_USED_TARGETS})
