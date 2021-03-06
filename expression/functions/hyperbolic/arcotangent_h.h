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
        inline value calculate(value arg) const override {
            return unary_calculator<T>::arcotangent_h(arg);
        }
    };

    namespace construct {
        template <typename T>
        auto arcotangent_h(math::expression_ptr const & arg) {
            return std::make_shared<math::arcotangent_h<T>>(arg);
        }
    }
}
