// expression header file

#pragma once

#include <map>
#include <memory>
#include <string>

#include "utility/definitions.h"

namespace math {
    class expression {
     public:
        virtual std::shared_ptr<expression> get_arg(size_t) = 0;
        virtual number evaluate(var_table const&) const = 0;
        virtual std::string to_string() const = 0;
        virtual OpPriority priority() const = 0;
        virtual bool is_associative() const = 0;
    };
}
