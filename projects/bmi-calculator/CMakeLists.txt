cmake_minimum_required(VERSION 3.16)

project(BMICalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(bmi_calculator
    src/main.cpp
    src/BMICalculator.cpp
    src/BMICalculatorApp.cpp
)