//
// Created by DNS on 27.07.20.
//
#pragma once

#include "../binary_operation.h"

namespace math {
    template <typename U, typename V>
    class add : public binary_operation {
     public:
        using binary_operation::binary_operation;

        inline std::string to_string() const override {
            return make_string("+");
        }

        inline OpPriority priority() const override {
            return OpPriority::Add;
        }

        inline bool is_commutative() const override {
            return true;
        }

     protected:
        inline value calculate(value lhs, value rhs) const override {
            return binary_calculator<U, V>::add(lhs, rhs);
        }
    };
}
