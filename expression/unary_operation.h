// unary expression header file

#pragma once

#include <memory>

#include "expression.h"

namespace math {
    class unary_operation : public expression {
    public:
        explicit unary_operation(expression_ptr);

        expression_ptr get_arg(size_t) override;
        const_expression_ptr get_arg(size_t) const override;
        expression_ptr arg();
        const_expression_ptr arg() const;
        number evaluate(var_table const&, base_calculator const&) const override;
        bool equals(expression const&, base_calculator const&) const override;
        OpPriority priority() const override;
        bool is_commutative() const override;

    protected:
        virtual number calculate(number, base_calculator const&) const = 0;
        std::string make_string(std::string const&, base_calculator const&) const;

        expression_ptr arg_;
    };
}
