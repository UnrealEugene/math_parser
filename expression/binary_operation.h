// binary expression header file

#pragma once

#include <memory>

#include "expression.h"

namespace math {
    class binary_operation : public expression {
     public:
        binary_operation(expression_ptr, expression_ptr);

        expression_ptr get_arg(size_t) override;
        const_expression_ptr get_arg(size_t) const override;
        expression_ptr left();
        const_expression_ptr left() const;
        expression_ptr right();
        const_expression_ptr right() const;
        number evaluate(var_table const&) const override;
        bool equals(expression const&) const override;

     protected:
        virtual number calculate(number, number) const = 0;
        std::string make_string(std::string const& sign) const;

        expression_ptr left_, right_;
    };
}
