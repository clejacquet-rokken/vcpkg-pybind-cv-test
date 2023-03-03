cmake_minimum_required(VERSION 3.15)

project(PybindTest)

find_package(pybind11 CONFIG REQUIRED)

add_executable(PybindTest main.cpp)

target_link_libraries(PybindTest PUBLIC pybind11::embed)

if(CUSTOM_SYS_PATH)
  target_compile_definitions(PybindTest PRIVATE CUSTOM_SYS_PATH="${CUSTOM_SYS_PATH}")
endif()
