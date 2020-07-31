//
// Created by DNS on 29.07.20.
//
#pragma once

#include <memory>
#include <map>
#include <string>

namespace math {
    struct number;
    class expression;
    using expression_ptr = std::shared_ptr<expression>;
    using const_expression_ptr = std::shared_ptr<expression const>;
    using var_table = std::map<std::string, number>;

    bool less_priority(expression const&, expression const&);
    bool equal_priority(expression const&, expression const&);

    enum OpPriority {
        Add = 0,
        Multiply,
        Power,
        Unary,
        Highest
    };
}