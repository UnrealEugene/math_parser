// unary expression header file

#pragma once

#include <memory>

#include "expression.h"

namespace math {
    class unary_operation : public expression {
    public:
        explicit unary_operation(std::shared_ptr<expression>);

        std::shared_ptr<expression> get_arg(size_t) override;
        std::shared_ptr<expression> arg();
        number evaluate(var_table const&) const override;
        OpPriority priority() const override;
        bool is_associative() const override;

    protected:
        virtual number calculate(number) const = 0;
        std::string make_string(std::string const& sign) const;

        expression_ptr arg_;
    };
}
