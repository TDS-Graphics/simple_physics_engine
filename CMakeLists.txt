cmake_minimum_required(VERSION 3.15)
project(physics)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party/glm)
add_subdirectory(third_party/raylib)

add_library(imgui STATIC
    third_party/imgui/imgui.cpp
    third_party/imgui/imgui_draw.cpp
    third_party/imgui/imgui_tables.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/imgui_demo.cpp
)
target_include_directories(imgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/third_party/imgui)
target_link_libraries(imgui PUBLIC raylib)
target_compile_definitions(imgui PUBLIC IMGUI_DISABLE_OBSOLETE_FUNCTIONS IMGUI_DISABLE_OBSOLETE_KEYIO)

add_library(rlImGui STATIC third_party/rlImGui/rlImGui.cpp)
target_include_directories(rlImGui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/third_party/rlImGui)
target_link_libraries(rlImGui PUBLIC imgui raylib)

add_library(framework INTERFACE)
target_include_directories(framework INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(framework INTERFACE glm raylib rlImGui)

add_subdirectory(samples)
