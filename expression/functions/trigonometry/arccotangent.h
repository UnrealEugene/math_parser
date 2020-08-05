#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class arccotangent : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("arcctg");
        }

    protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::arccotangent(arg);
        }
    };

    namespace construct {
        template <typename T>
        auto arccotangent(math::expression_ptr const & arg) {
            return std::make_shared<math::arccotangent<T>>(arg);
        }
    }
}
