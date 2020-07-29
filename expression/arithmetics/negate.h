//
// Created by DNS on 27.07.20.
//
#pragma once

#include "../unary_expression.h"

namespace math {
    class negate : public unary_expression {
    public:
        using unary_expression::unary_expression;

        inline std::string to_string() override {
            return make_string("-");
        }

    protected:
        inline number calculate(number arg) override {
            return -arg;
        }
    };
}
