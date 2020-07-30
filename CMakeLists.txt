# cmake_minimum_required(VERSION <specify CMake version here>)
project(math_parser)

set(CMAKE_CXX_STANDARD 17)

add_executable(math_parser
        main.cpp


        expression/expression.h

        expression/binary_operation.h 
        expression/binary_operation.cpp

        expression/unary_operation.h 
        expression/unary_operation.cpp

        expression/utility/value.h

        expression/arithmetics/add.h 
        expression/arithmetics/subtract.h
        expression/arithmetics/multiply.h 
        expression/arithmetics/divide.h
        expression/arithmetics/negate.h 

        expression/utility/variable.h 
        expression/utility/definitions.h 
        expression/utility/definitions.cpp 

        expression/functions/power.h 
        expression/functions/natural_logarithm.h 
        expression/functions/exponential.h)
