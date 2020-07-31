#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    class sine : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string(base_calculator const& calc) const override {
            return make_string("sin", calc);
        }

    protected:
        inline number calculate(number arg, base_calculator const& calc) const override {
            return calc.sine(arg);
        }
    };
}
