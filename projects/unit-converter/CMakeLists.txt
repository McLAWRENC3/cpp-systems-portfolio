cmake_minimum_required(VERSION 3.16)

project(UnitConverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(unit_converter
    src/main.cpp
    src/UnitConverterApp.cpp
)