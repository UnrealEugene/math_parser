#pragma once

#include <cmath>

#include "../unary_operation.h"

namespace math {
    template <typename T>
    class natural_logarithm : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("ln");
        }

    protected:
        inline number calculate(number arg) const override {
            return unary_calculator<T>::natural_logarithm(arg);
        }
    };

    namespace construct {
        template <typename T>
        auto natural_logarithm(math::expression_ptr const & arg) {
            return std::make_shared<math::natural_logarithm<T>>(arg);
        }
    }
}
