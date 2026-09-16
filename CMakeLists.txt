cmake_minimum_required(VERSION 3.15)
project(physics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party/glm)
add_subdirectory(third_party/raylib)

add_library(framework INTERFACE)
target_include_directories(framework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(framework INTERFACE glm raylib)

add_subdirectory(samples)
