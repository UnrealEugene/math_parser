//
// Created by DNS on 01.08.20.
//
#pragma once

#include "../unary_operation.h"

namespace math {
    template <typename To, typename From>
    class cast : public unary_operation {
    public:
        using unary_operation::unary_operation;

        inline std::string to_string() const override {
            return make_string("");
        }

        inline value evaluate(var_table const& table) const override {
            return value(static_cast<To>(arg_->evaluate(table).unfold<From>()));
        }

    protected:
        inline value calculate(value arg) const override {  // not usable
            return 0;
        }
    };

    namespace construct {
        template <typename To, typename From>
        auto cast(math::expression_ptr const& arg) {
            return std::make_shared<math::cast<To, From>>(arg);
        }
    }
}
