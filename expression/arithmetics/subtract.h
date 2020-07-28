//
// Created by DNS on 28.07.20.
//
#pragma once

#include "../binary_expression.h"

namespace math {
    class subtract : public binary_expression {
     public:
        using binary_expression::binary_expression;

     protected:
        inline number calculate(number lhs, number rhs) override {
            return lhs - rhs;
        }
    };
}
