// variable header file

#pragma once

#include <memory>
#include <string>
#include <utility>
#include <typeindex>
#include <typeinfo>

#include "../expression.h"

namespace math {
    class variable : public expression {
     public:
        inline explicit variable(std::string var) : var_(std::move(var)) { }
        inline expression_ptr get_arg(size_t) override {
            return nullptr;
        }

        inline const_expression_ptr get_arg(size_t) const override {
            return nullptr;
        }

        inline std::string to_string() const override {
            return var_;
        }

        inline OpPriority priority() const override {
            return OpPriority::Highest;
        }

        inline bool is_commutative() const override {
            return true;
        }

        inline number evaluate(var_table const& table) const override {
            return table.at(var_);
        }

        inline bool equals(expression const& rhs) const override {
            if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
                return false;
            auto const& t_rhs = static_cast<variable const&>(rhs);
            return var_ == t_rhs.to_string();
        }

    protected:
        std::string var_;
    };
}