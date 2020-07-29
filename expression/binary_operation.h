// binary expression header file

#pragma once

#include <memory>

#include "expression.h"

namespace math {
    class binary_operation : public expression {
     public:
        binary_operation(std::shared_ptr<expression>, std::shared_ptr<expression>);

        std::shared_ptr<expression> get_arg(size_t) override;
        std::shared_ptr<expression> left();
        std::shared_ptr<expression> right();
        number evaluate(var_table const&) const override;

     protected:
        virtual number calculate(number, number) const = 0;
        std::string make_string(std::string const& sign) const;

        expression_ptr left_, right_;
    };
}
