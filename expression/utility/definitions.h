//
// Created by DNS on 29.07.20.
//
#pragma once

#include <memory>
#include <map>
#include <string>

namespace math {
    class expression;
    typedef std::shared_ptr<expression> expression_ptr;
    typedef int64_t number;
    typedef std::map<std::string, number> var_table;

    bool less_priority(expression const&, expression const&);
    bool equal_priority(expression const&, expression const&);

    enum OpPriority {
        Add = 0,
        Multiply,
        Unary,
        Highest
    };
}