// expression header file

#pragma once

namespace math {
    typedef uint64_t number;

    class expression {
     public:
        virtual std::shared_ptr<expression> get_arg(size_t) = 0;
        virtual number evaluate() = 0;
        virtual std::string to_string() = 0;
    };
}
