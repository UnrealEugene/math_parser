//
// Created by DNS on 27.07.20.
//
#pragma once
#include <memory>

#include "expression.h"

namespace math {
    class binary_expression : public expression {
     public:
        binary_expression(std::shared_ptr<expression>, std::shared_ptr<expression>);

        std::shared_ptr<expression> get_arg(size_t) override;
        std::shared_ptr<expression> left();
        std::shared_ptr<expression> right();
        number evaluate() override;

     protected:
        virtual number calculate(number, number) = 0;
        std::string make_string(std::string const& sign);

        std::shared_ptr<expression> left_, right_;
    };
}
