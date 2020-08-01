#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class tangent_h : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("tgh");
        }

    protected:
        inline value calculate(value arg) const override {
            return unary_calculator<T>::tangent_h(arg);
        }
    };
}
