//
// Created by DNS on 28.07.20.
//
#pragma once
#include <memory>

#include "expression.h"

namespace math {
    class value : expression {
     public:
        inline explicit value(number v) : val_(v) { }
        inline std::shared_ptr<expression> get_arg(size_t) override {
            return nullptr;
        }

     protected:
        inline number evaluate() override {
            return val_;
        }

        number val_;
    };
}
