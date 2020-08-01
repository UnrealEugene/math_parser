// unary expression cpp file

#include <cstddef>
#include <utility>
#include <sstream>
#include <typeindex>

#include "unary_operation.h"

namespace math {
    unary_operation::unary_operation(expression_ptr a) :
            arg_(std::move(a)) { }

    expression_ptr unary_operation::get_arg(size_t index) {
        if (index == 0)
            return arg_;
        return nullptr;
    }

    const_expression_ptr unary_operation::get_arg(size_t index) const {
        if (index == 0)
            return arg_;
        return nullptr;
    }

    expression_ptr unary_operation::arg() {
        return arg_;
    }

    const_expression_ptr unary_operation::arg() const {
        return arg_;
    }

    value unary_operation::evaluate(var_table const& table) const {
        return calculate(arg_->evaluate(table));
    }

    bool unary_operation::equals(expression const& rhs) const {
        if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
            return false;
        auto const& t_rhs = static_cast<unary_operation const&>(rhs);
        return arg_->equals(*t_rhs.arg());
    }

    OpPriority unary_operation::priority() const {
        return OpPriority::Unary;
    }

    bool unary_operation::is_commutative() const {
        return true;
    }

    std::string unary_operation::make_string(std::string const& sign) const {
        std::stringstream res;
        res << sign << "(" << arg_->to_string() << ")";
        return res.str();
    }
}
