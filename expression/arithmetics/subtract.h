//
// Created by DNS on 28.07.20.
//
#pragma once

#include "../binary_expression.h"

namespace math {
    class subtract : binary_expression {
    public:
        using binary_expression::binary_expression;

    protected:
        inline number calculate(number left, number right) override {
            return left - right;
        }
    };
}
