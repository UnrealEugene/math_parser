#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class arctangent : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("arctg");
        }

    protected:
        inline value calculate(value arg) const override {
            return unary_calculator<T>::arctangent(arg);
        }
    };

    namespace construct {
        template <typename T>
        auto arctangent(math::expression_ptr const & arg) {
            return std::make_shared<math::arctangent<T>>(arg);
        }
    }
}
