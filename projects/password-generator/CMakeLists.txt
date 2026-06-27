cmake_minimum_required(VERSION 3.16)

project(PasswordGenerator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(password_generator
    src/main.cpp
    src/PasswordGenerator.cpp
    src/PasswordGeneratorApp.cpp
)