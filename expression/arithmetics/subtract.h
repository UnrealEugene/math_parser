//
// Created by DNS on 28.07.20.
//
#pragma once

#include "../binary_operation.h"

namespace math {
    template <typename U, typename V>
    class subtract : public binary_operation {
     public:
        using binary_operation::binary_operation;

        inline std::string to_string() const override {
            return make_string("-");
        }

        inline OpPriority priority() const override {
            return OpPriority::Add;
        }

        inline bool is_commutative() const override {
            return false;
        }

     protected:
        inline value calculate(value lhs, value rhs) const override {
            return binary_calculator<U, V>::subtract(lhs, rhs);
        }
    };

    namespace construct {
        template <typename U, typename V>
        auto subtract(math::expression_ptr const & left, math::expression_ptr const & right) {
            return std::make_shared<math::subtract<U, V>>(left, right);
        }
    }
}
