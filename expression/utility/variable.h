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
        inline std::shared_ptr<expression> get_arg(size_t) override {
            return nullptr;
        }

        inline std::string to_string() override {
            return var_;
        }

     protected:
        inline number evaluate(var_table const& table) override {
            return table.at(var_);
        }

        std::string var_;
    };
}