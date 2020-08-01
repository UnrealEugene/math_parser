#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class arcotangent_h : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("arctgh");
        }

    protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::arcotangent_h(arg);
        }
    };
}
