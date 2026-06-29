cmake_minimum_required(VERSION 3.16)

project(BankingSimulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(banking_simulator
    src/main.cpp
    src/Bank.cpp
    src/BankingApp.cpp
)