//
// Created by DNS on 27.07.20.
//
#pragma once

#include "../unary_operation.h"

namespace math {
    template <typename T>
    class negate : public unary_operation {
     public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("-");
        }

     protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::negate(arg);
        }
    };
}
