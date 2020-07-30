#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    class tangent : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("tg");
        }

    protected:
        inline number calculate(number arg) const override {
            return tan(arg);
        }
    };
}
