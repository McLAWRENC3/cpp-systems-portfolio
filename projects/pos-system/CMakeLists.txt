cmake_minimum_required(VERSION 3.16)

project(POSSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(pos_system
    src/main.cpp
    src/POSSystem.cpp
    src/POSApp.cpp
)