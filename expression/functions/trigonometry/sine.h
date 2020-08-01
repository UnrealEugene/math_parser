#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class sine : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("sin");
        }

    protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::sine(arg);
        }
    };
}
