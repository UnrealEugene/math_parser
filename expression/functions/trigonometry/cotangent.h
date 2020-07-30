#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    class cotangent : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("ctg");
        }

    protected:
        inline number calculate(number arg) const override {
            return 1 / tan(arg);
        }
    };
}