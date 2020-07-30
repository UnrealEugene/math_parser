#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    class arccotangent : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("arcctg");
        }

    protected:
        inline number calculate(number arg) const override {
            return acos(0) - atan(arg);
        }
    };
}
