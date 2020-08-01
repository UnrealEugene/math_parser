// constant header file

#pragma once

#include <memory>
#include <string>
#include <typeinfo>
#include <typeindex>
#include <utility>

#include "../expression.h"
#include "calculator/equals_calculator.h"
#include "calculator/string_calculator.h"

namespace math {
    template <typename T>
    class constant : public expression {
     public:
        inline explicit constant(T const& v) : val_(v) { }
        inline expression_ptr get_arg(size_t) override {
            return nullptr;
        }

        inline const_expression_ptr get_arg(size_t) const override {
            return nullptr;
        }

        inline value val() const {
            return val_;
        }

        inline std::string to_string() const override {
            return string_calculator<T>::to_string(val_);
        }

        inline OpPriority priority() const override {
            return OpPriority::Highest;
        }

        inline bool is_commutative() const override {
            return true;
        }

        inline value evaluate(var_table const&) const override {
            return val_;
        }

        inline bool equals(expression const& rhs) const override {
            if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
                return false;
            auto const& t_rhs = static_cast<constant const&>(rhs);
            return equals_calculator<T>::equals(val_, t_rhs.val());
        }

    private:
        value val_;
    };
}
