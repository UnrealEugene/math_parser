// unary expression cpp file

#include <cstddef>
#include <utility>
#include <sstream>

#include "unary_expression.h"

namespace math {
        unary_expression::unary_expression(std::shared_ptr<expression> a) :
            arg_(std::move(a)) { }

    std::shared_ptr<expression> unary_expression::get_arg(size_t index) {
        if (index == 0)
            return arg_;
        return nullptr;
    }

    std::shared_ptr<expression> unary_expression::arg() {
        return arg_;
    }

    number unary_expression::evaluate() {
        return calculate(arg_->evaluate());
    }

    std::string unary_expression::make_string(std::string const& sign) {
        std::stringstream res;
        res << sign << "(" << arg_->to_string() << ")";
        return res.str();
    }
}