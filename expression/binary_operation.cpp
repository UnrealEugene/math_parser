// binary expression cpp file

#include <cstddef>
#include <utility>
#include <sstream>
#include <typeinfo>
#include <typeindex>

#include "binary_operation.h"

namespace math {
    binary_operation::binary_operation(expression_ptr l, expression_ptr r) :
        left_(std::move(l)), right_(std::move(r)) { }

    expression_ptr binary_operation::get_arg(size_t index) {
        switch (index) {
            case 0:
                return left_;
            case 1:
                return right_;
            default:
                return nullptr;
        }
    }

    const_expression_ptr binary_operation::get_arg(size_t index) const {
        switch (index) {
            case 0:
                return left_;
            case 1:
                return right_;
            default:
                return nullptr;
        }
    }

    expression_ptr binary_operation::left() {
        return left_;
    }

    const_expression_ptr binary_operation::left() const {
        return left_;
    }

    expression_ptr binary_operation::right() {
        return right_;
    }

    const_expression_ptr binary_operation::right() const {
        return right_;
    }

    number binary_operation::evaluate(var_table const& table) const {
        return calculate(left_->evaluate(table), right_->evaluate(table));
    }

    bool binary_operation::equals(expression const& rhs) const {
        if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
            return false;
        auto const& t_rhs = static_cast<binary_operation const&>(rhs);
        return left_->equals(*t_rhs.left()) && right_->equals(*t_rhs.right());
    }

    static void add_member_brackets_(std::stringstream& ss, expression_ptr const& p, bool need_brackets) {
        if (need_brackets)
            ss << "(";
        ss << p->to_string();
        if (need_brackets)
            ss << ")";
    }

    std::string binary_operation::make_string(std::string const& sign) const {
        std::stringstream res;
        add_member_brackets_(res, left_, less_priority(*left_, *this));
        res << " " << sign << " ";
        add_member_brackets_(res, right_, !(less_priority(*this, *right_) ||
                (equal_priority(*this, *right_) && is_commutative())));
        return res.str();
    }
}