# cmake_minimum_required(VERSION <specify CMake version here>)
project(math_parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(math_parser
        main.cpp
        expression/expression.h
        expression/binary_expression.h expression/binary_expression.cpp
        expression/unary_expression.h expression/unary_expression.cpp
        expression/utility/value.h
        expression/arithmetics/add.h expression/arithmetics/subtract.h
        expression/arithmetics/multiply.h expression/arithmetics/divide.h
        expression/arithmetics/negate.h expression/utility/variable.h)