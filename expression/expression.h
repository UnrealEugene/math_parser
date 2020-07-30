// expression header file

#pragma once

#include <map>
#include <memory>
#include <string>

#include "utility/definitions.h"

namespace math {
    class expression {
     public:
        virtual expression_ptr get_arg(size_t) = 0;
        virtual const_expression_ptr get_arg(size_t) const = 0;
        virtual number evaluate(var_table const&) const = 0;
        virtual std::string to_string() const = 0;
        virtual OpPriority priority() const = 0;
        virtual bool is_commutative() const = 0;
        virtual bool equals(expression const&) const = 0;
    };
}
