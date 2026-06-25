cmake_minimum_required(VERSION 3.16)

project(CurrencyConverter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(currency_converter
    src/main.cpp
    src/HttpClient.cpp
    src/CurrencyService.cpp
    src/CurrencyConverterApp.cpp
)

target_link_libraries(currency_converter curl)