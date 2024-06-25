find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)

add_library(IndexWindow IndexWindow.cpp IndexWindow.hpp)
target_link_libraries(IndexWindow PRIVATE Qt6::Widgets)
