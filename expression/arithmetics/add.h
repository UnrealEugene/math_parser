//
// Created by DNS on 27.07.20.
//
#pragma once

#include "../binary_expression.h"

namespace math {
    class add : public binary_expression {
     public:
        using binary_expression::binary_expression;

        inline std::string to_string() override {
            return make_string("+");
        }

    protected:
        inline number calculate(number lhs, number rhs) override {
            return lhs + rhs;
        }
    };
}
