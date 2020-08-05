#pragma once

#include <cmath>

#include "../../unary_operation.h"

namespace math {
    template <typename T>
    class cotangent_h : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("ctgh");
        }
        
    protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::cotangent_h(arg);
        }
    };

    namespace construct {
        template <typename T>
        auto cotangent_h(math::expression_ptr const & arg) {
            return std::make_shared<math::cotangent_h<T>>(arg);
        }
    }
}
