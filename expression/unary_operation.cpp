// unary expression cpp file

#include <cstddef>
#include <utility>
#include <sstream>

#include "unary_operation.h"
#include "utility/definitions.h"

namespace math {
    unary_operation::unary_operation(std::shared_ptr<expression> a) :
            arg_(std::move(a)) { }

    std::shared_ptr<expression> unary_operation::get_arg(size_t index) {
        if (index == 0)
            return arg_;
        return nullptr;
    }

    std::shared_ptr<expression> unary_operation::arg() {
        return arg_;
    }

    number unary_operation::evaluate(var_table const& table) const {
        return calculate(arg_->evaluate(table));
    }

    OpPriority unary_operation::priority() const {
        return OpPriority::Unary;
    }

    bool unary_operation::is_associative() const {
        return true;
    }

    std::string unary_operation::make_string(std::string const& sign) const {
        std::stringstream res;
        res << sign << "(" << arg_->to_string() << ")";
        return res.str();
    }
}