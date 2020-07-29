// value header file

#pragma once

#include <memory>
#include <string>

#include "../expression.h"

namespace math {
    class value : public expression {
     public:
        inline explicit value(number v) : val_(v) { }
        inline std::shared_ptr<expression> get_arg(size_t) override {
            return nullptr;
        }

        inline std::string to_string() override {
            return std::to_string(val_);
        }

     protected:
        inline number evaluate(var_table const&) override {
            return val_;
        }

        number val_;
    };
}
