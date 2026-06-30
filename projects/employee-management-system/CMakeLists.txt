cmake_minimum_required(VERSION 3.16)

project(EmployeeManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories("C:/msys64/ucrt64/include")

link_directories("C:/msys64/ucrt64/lib")

add_executable(employee_management_system
    src/main.cpp
    src/DatabaseManager.cpp
    src/DepartmentService.cpp
    src/EmployeeService.cpp
    src/SalaryService.cpp
)

target_link_libraries(employee_management_system pqxx pq)