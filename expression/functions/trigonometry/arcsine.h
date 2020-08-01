#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class arcsine : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("arcsin");
        }

    protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::arcsine(arg);
        }
    };
}
