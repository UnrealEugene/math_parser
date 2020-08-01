#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class cosine : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("cos");
        }

    protected:
        inline value calculate(value arg) const override {
            return unary_calculator<T>::cosine(arg);
        }
    };
}
