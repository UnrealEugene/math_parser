//
// Created by DNS on 29.07.20.
//
#pragma once

#include "../binary_operation.h"

namespace math {
    template <typename U, typename V>
    class divide: public binary_operation {
     public:
        using binary_operation::binary_operation;

        inline std::string to_string() const override {
            return make_string("/");
        }

        inline OpPriority priority() const override {
            return OpPriority::Multiply;
        }

        inline bool is_commutative() const override {
            return false;
        }

     protected:
        inline number calculate(number lhs, number rhs) const override {
            return binary_calculator<U, V>::divide(lhs, rhs);
        }
    };

    namespace construct {
        template <typename U, typename V>
        auto divide(math::expression_ptr const & left, math::expression_ptr const & right) {
            return std::make_shared<math::devide<U, V>>(left, right);
        }
    }
}
