#pragma once

#include <cmath>

#include "../binary_operation.h"

namespace math {
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
        /*
        !!!Expecting support int64_t and double!!!
        inline number calculate(number lhs, number rhs) const override {
            number result = 1;
            while (rhs > 0) {
                if (rhs % 2 == 0) { 
                    result *= lhs;
                }
                lhs *= lhs;
                rhs /= 2;
            }
            return result;
        }
        */

        inline number calculate(number lhs, number rhs) const override {
            return pow(lhs, rhs);
        }
    };
}
