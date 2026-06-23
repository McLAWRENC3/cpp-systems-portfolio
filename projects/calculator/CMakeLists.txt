cmake_minimum_required(VERSION 3.16)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(calculator
src/main.cpp
src/Parser.cpp
src/Operation.cpp
src/Calculator.cpp
)
