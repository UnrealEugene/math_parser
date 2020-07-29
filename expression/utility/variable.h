// variable header file

#pragma once

#include <memory>
#include <string>
#include <utility>

#include "../expression.h"

namespace math {
    class variable : public expression {
     public:
        inline explicit variable(std::string var) : var_(std::move(var)) { }
        inline expression_ptr get_arg(size_t) override {
            return nullptr;
        }

        inline std::string to_string() const override {
            return var_;
        }

        inline OpPriority priority() const override {
            return OpPriority::Highest;
        }

        inline bool is_associative() const override {
            return true;
        }

     protected:
        inline number evaluate(var_table const& table) const override {
            return table.at(var_);
        }

        std::string var_;
    };
}