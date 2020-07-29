// unary expression header file

#pragma once

#include <memory>

#include "expression.h"

namespace math {
    class unary_expression : public expression {
    public:
        explicit unary_expression(std::shared_ptr<expression>);

        std::shared_ptr<expression> get_arg(size_t) override;
        std::shared_ptr<expression> arg();
        number evaluate(var_table const&) override;

    protected:
        virtual number calculate(number) = 0;
        std::string make_string(std::string const& sign);

        std::shared_ptr<expression> arg_;
    };
}
