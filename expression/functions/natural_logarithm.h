#pragma once

#include <cmath>

#include "../unary_operation.h"

namespace math {
    class natural_logarithm : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("ln");
        }

    protected:
        inline number calculate(number arg) const override {
            return log(arg);
        }
    };
}
