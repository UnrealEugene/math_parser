//
// Created by DNS on 29.07.20.
//
#pragma once

#include "../binary_operation.h"

namespace math {
    class multiply : public binary_operation {
     public:
        using binary_operation::binary_operation;

        inline std::string to_string(base_calculator const& calc) const override {
            return make_string("*", calc);
        }

        inline OpPriority priority() const override {
            return OpPriority::Multiply;
        }

        inline bool is_commutative() const override {
            return true;
        }

     protected:
        inline number calculate(number lhs, number rhs, base_calculator const& calc) const override {
            return calc.multiply(lhs, rhs);
        }
    };
}
