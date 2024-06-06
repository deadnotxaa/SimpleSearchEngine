add_executable(index index.cpp)
add_executable(search search.cpp)

target_link_libraries(index PRIVATE Protobuf Qt6::Widgets)
target_link_libraries(search PRIVATE Protobuf Qt6::Widgets)

target_include_directories(index PUBLIC ${PROJECT_SOURCE_DIR})
target_include_directories(search PUBLIC ${PROJECT_SOURCE_DIR})