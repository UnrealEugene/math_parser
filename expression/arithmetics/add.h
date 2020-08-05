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
        inline number calculate(number lhs, number rhs) const override {
            return binary_calculator<U, V>::add(lhs, rhs);
        }
    };
    
    namespace construct {
        template <typename U, typename V>
        auto add(math::expression_ptr const& left, math::expression_ptr const& right) {
            return std::make_shared<math::add<U, V>>(left, right);
        }
    }
}
