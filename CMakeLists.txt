# cmake_minimum_required(VERSION <specify CMake version here>)
project(math_parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(math_parser
        main.cpp

        expression/binary_operation.cpp
        expression/unary_operation.cpp
        expression/utility/definitions.cpp)
