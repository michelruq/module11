cmake_minimum_required(VERSION 3.5)

project(Module11)

add_executable(sort main.cpp )

include_directories(./sort ./files)

set_target_properties(
    sort PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)	