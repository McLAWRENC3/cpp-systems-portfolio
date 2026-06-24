cmake_minimum_required(VERSION 3.16)

project(ScientificCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(scientific_calculator
    src/main.cpp
    src/Calculator.cpp
    src/OperationFactory.cpp
)