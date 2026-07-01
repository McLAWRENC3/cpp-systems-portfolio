cmake_minimum_required(VERSION 3.16)
project(EcommerceBackend)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories("C:/msys64/ucrt64/include")

link_directories("C:/msys64/ucrt64/lib")

add_executable(ecommerce_backend
    src/main.cpp
    src/DatabaseManager.cpp
    src/UserService.cpp
    src/ProductService.cpp
    src/CartService.cpp
    src/OrderService.cpp
)

target_link_libraries(ecommerce_backend pqxx pq)