#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    class arsine_h : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string(base_calculator const& calc) const override {
            return make_string("arsinh", calc);
        }

    protected:
        inline number calculate(number arg, base_calculator const& calc) const override {
            return calc.arsine_h(arg);
        }
    };
}
