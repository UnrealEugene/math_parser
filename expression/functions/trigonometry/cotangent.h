#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class cotangent : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("ctg");
        }

    protected:
        inline value calculate(value arg) const override {
            return unary_calculator<T>::cotangent(arg);
        }
    };
}
