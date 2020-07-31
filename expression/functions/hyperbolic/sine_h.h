#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    class sine_h : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string(base_calculator const& calc) const override {
            return make_string("sinh", calc);
        }

    protected:
        inline number calculate(number arg, base_calculator const& calc) const override {
            return calc.sine_h(arg);
        }
    };
}
