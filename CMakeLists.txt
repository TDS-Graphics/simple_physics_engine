cmake_minimum_required(VERSION 3.15)
project(physics)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party/glm)
add_subdirectory(third_party/raylib)

include_directories(third_party/glm)
include_directories(third_party/raylib)

set(SOURCES_FILES ${CMAKE_SOURCE_DIR}/src/main.cpp )



add_executable(physics ${SOURCES_FILES})


target_link_libraries(physics PRIVATE glm raylib)
