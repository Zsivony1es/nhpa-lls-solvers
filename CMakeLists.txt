cmake_minimum_required(VERSION 3.26)


project(
        Homework1
        VERSION 0.1
        DESCRIPTION "Homework Project for Numerical High Performance Algorithms class, containing implementations of 4 different LLS solvers."
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recursively search source files in src folder
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(Homework1 main.cpp ${SRC_FILES})

target_include_directories(Homework1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

