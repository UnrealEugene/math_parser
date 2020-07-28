# cmake_minimum_required(VERSION <specify CMake version here>)
project(math_parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(math_parser main.cpp expression/expression.h expression/binary_expression.h expression/binary_expression.cpp)
add_executable(math_parser main.cpp expression/arithmetics/add.h expression/value.h expression/arithmetics/subtract.h)