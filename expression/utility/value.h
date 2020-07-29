// value header file

#pragma once

#include <memory>
#include <string>

#include "../expression.h"

namespace math {
    class value : public expression {
     public:
        inline explicit value(number v) : val_(v) { }
        inline expression_ptr get_arg(size_t) override {
            return nullptr;
        }

        inline std::string to_string() const override {
            return std::to_string(val_);
        }

        inline OpPriority priority() const override {
            return OpPriority::Highest;
        }

        inline bool is_associative() const override {
            return true;
        }

     protected:
        inline number evaluate(var_table const&) const override {
            return val_;
        }

        number val_;
    };
}
