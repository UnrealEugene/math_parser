// expression header file

#pragma once

#include <map>

namespace math {
    typedef uint64_t number;
    typedef std::map<std::string, number> var_table;

    class expression {
     public:
        virtual std::shared_ptr<expression> get_arg(size_t) = 0;
        virtual number evaluate(var_table const&) = 0;
        virtual std::string to_string() = 0;
    };
}
