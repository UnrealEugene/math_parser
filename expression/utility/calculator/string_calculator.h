//
// Created by DNS on 01.08.20.
//

#pragma once

#include <string>

#include "../number.h"

namespace math {
    template <typename T>
    struct string_calculator {
        static std::string to_string(number const& x) {
            return std::to_string(x.value<T>());
        }
    };
}