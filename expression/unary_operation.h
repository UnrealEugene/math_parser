// unary expression header file

#pragma once

#include <memory>

#include "expression.h"
#include "utility/calculator/unary_calculator.h"

namespace math {
    class unary_operation : public expression {
    public:
        explicit unary_operation(expression_ptr);
        ~unary_operation() override = default;

        expression_ptr get_arg(size_t) override;
        const_expression_ptr get_arg(size_t) const override;
        expression_ptr arg();
        const_expression_ptr arg() const;
        value evaluate(var_table const&) const override;
        bool equals(expression const&) const override;
        OpPriority priority() const override;
        bool is_commutative() const override;

    protected:
        virtual value calculate(value) const = 0;
        std::string make_string(std::string const&) const;

        expression_ptr arg_;
    };
}
