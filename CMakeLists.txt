cmake_minimum_required(VERSION 3.28)
project(
        SimpleSearchEngine
        DESCRIPTION "Simple search engine for filesystem"
        VERSION 1.0
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_OSX_ARCHITECTURES x86_64)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra") # -pedantic -Werror

find_package(absl REQUIRED)
set(protobuf_ABSL_USED_TARGETS
        absl::absl_check
        absl::absl_log
        absl::algorithm
        absl::base
        absl::bind_front
        absl::bits
        absl::btree
        absl::cleanup
        absl::cord
        absl::core_headers
        absl::debugging
        absl::die_if_null
        absl::dynamic_annotations
        absl::flags
        absl::flat_hash_map
        absl::flat_hash_set
        absl::function_ref
        absl::hash
        absl::layout
        absl::log_initialize
        absl::log_severity
        absl::memory
        absl::node_hash_map
        absl::node_hash_set
        absl::optional
        absl::span
        absl::status
        absl::statusor
        absl::strings
        absl::synchronization
        absl::time
        absl::type_traits
        absl::utility
        absl::variant
)

include(FindProtobuf)
find_package(Protobuf REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${Protobuf_INCLUDE_DIRS} ${absl_INCLUDE_DIRS})

protobuf_generate_cpp(PROTO_SRC PROTO_HEADER proto/.proto)
add_library(proto ${PROTO_HEADER} ${PROTO_SRC})


# GTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

# QT
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# OpenMP
OPTION (USE_OpenMP "Use OpenMP" ON)
IF(USE_OpenMP)
    FIND_PACKAGE(OpenMP)
    IF(OPENMP_FOUND)
        SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    ENDIF()
ENDIF()

add_subdirectory(bin)
add_subdirectory(lib)
add_subdirectory(proto)

message(\n)
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")
message(CMAKE_CXX_STANDARD="${CMAKE_CXX_STANDARD}")
message(CMAKE_CXX_FLAGS="${CMAKE_CXX_FLAGS}")
message(CMAKE_C_FLAGS="${CMAKE_C_FLAGS}")
message(CMAKE_OSX_ARCHITECTURES="${CMAKE_OSX_ARCHITECTURES}")
message(CMAKE_CXX_COMPILER="${CMAKE_CXX_COMPILER}")
message(CMAKE_C_COMPILER="${CMAKE_C_COMPILER}")
message(Protobuf_LIBRARIES="${Protobuf_LIBRARIES}")
message(CMAKE_CURRENT_BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")
message(Protobuf_INCLUDE_DIRS="${Protobuf_INCLUDE_DIRS}")
message(\n)
