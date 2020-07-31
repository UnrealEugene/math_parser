#pragma once

#include <cmath>

#include "../binary_operation.h"

namespace math {
    class power : public binary_operation {
    public:
        using binary_operation::binary_operation;

        inline std::string to_string(base_calculator const& calc) const override {
            return make_string("**", calc);
        }

        inline OpPriority priority() const override {
            return OpPriority::Power;
        }

        inline bool is_commutative() const override {
            return false;
        }

    protected:
        inline number calculate(number lhs, number rhs, base_calculator const& calc) const override {
            return calc.power(lhs, rhs);
        }
    };
}
