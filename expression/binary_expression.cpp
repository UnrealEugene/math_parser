//
// Created by DNS on 27.07.20.
//
#include <cstddef>
#include <utility>

#include "binary_expression.h"

namespace math {
    binary_expression::binary_expression(std::shared_ptr<expression> l, std::shared_ptr<expression> r) :
        left_(std::move(l)), right_(std::move(r)) { }

    std::shared_ptr<expression> binary_expression::get_arg(size_t index) {
        switch (index) {
            case 0:
                return left_;
            case 1:
                return right_;
            default:
                return nullptr;
        }
    }

    std::shared_ptr<expression> binary_expression::left() {
        return left_;
    }

    std::shared_ptr<expression> binary_expression::right() {
        return right_;
    }

    number binary_expression::evaluate() {
        return calculate(left_->evaluate(), right_->evaluate());
    }
}

