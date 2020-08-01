//
// Created by DNS on 01.08.20.
//

#pragma once

#include <string>

#include "../value.h"

namespace math {
    template <typename T>
    struct string_calculator {
        static std::string to_string(value const& x) {
            using std::to_string;
            return to_string(x.unfold<T>());
        }
    };
}