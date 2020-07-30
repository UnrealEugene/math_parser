// value header file

#pragma once

#include <memory>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "../expression.h"

namespace math {
    class value : public expression {
     public:
        inline explicit value(number v) : val_(v) { }
        inline expression_ptr get_arg(size_t) override {
            return nullptr;
        }

        inline const_expression_ptr get_arg(size_t) const override {
            return nullptr;
        }

        inline number val() const {
            return val_;
        }

        inline std::string to_string() const override {
            return std::to_string(val_);
        }

        inline OpPriority priority() const override {
            return OpPriority::Highest;
        }

        inline bool is_commutative() const override {
            return true;
        }

        inline number evaluate(var_table const&) const override {
            return val_;
        }

        inline bool equals(expression const& rhs) const override {
            if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
                return false;
            auto const& t_rhs = static_cast<value const&>(rhs);
            return t_rhs.val() == val_;
        }

    protected:
        number val_;
    };
}
