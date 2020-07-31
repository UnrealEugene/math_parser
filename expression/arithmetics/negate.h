//
// Created by DNS on 27.07.20.
//
#pragma once

#include "../unary_operation.h"

namespace math {
    class negate : public unary_operation {
     public:
        using unary_operation::unary_operation;

        inline std::string to_string(base_calculator const& calc) const override {
            return make_string("-", calc);
        }

     protected:
        inline number calculate(number arg, base_calculator const& calc) const override {
            return calc.negate(arg);
        }
    };
}
