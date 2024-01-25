cmake_minimum_required(VERSION 3.5)

project(Module11)

add_executable(files main.cpp)

set_target_properties(
    files PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)	