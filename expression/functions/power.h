#pragma once

#include <cmath>

#include "../binary_operation.h"

namespace math {
    template <typename U, typename V>
    class power : public binary_operation {
    public:
        using binary_operation::binary_operation;

        inline std::string to_string() const override {
            return make_string("**");
        }

        inline OpPriority priority() const override {
            return OpPriority::Power;
        }

        inline bool is_commutative() const override {
            return false;
        }

    protected:
        inline value calculate(value lhs, value rhs) const override {
            return binary_calculator<U, V>::power(lhs, rhs);
        }
    };

    namespace construct {
        template <typename U, typename V>
        auto power(math::expression_ptr const & left, math::expression_ptr const & right) {
            return std::make_shared<math::power<U, V>>(left, right);
        }
    }
}
