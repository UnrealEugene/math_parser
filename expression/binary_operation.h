// binary expression header file

#pragma once

#include <memory>

#include "expression.h"

namespace math {
    class binary_operation : public expression {
     public:
        binary_operation(expression_ptr, expression_ptr);

        expression_ptr get_arg(size_t) override;
        expression_ptr left();
        expression_ptr right();
        number evaluate(var_table const&) const override;

     protected:
        virtual number calculate(number, number) const = 0;
        std::string make_string(std::string const& sign) const;

        expression_ptr left_, right_;
    };
}
