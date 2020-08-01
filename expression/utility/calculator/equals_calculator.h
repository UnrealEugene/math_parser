//
// Created by DNS on 01.08.20.
//

#pragma once

#include <typeinfo>
#include <typeindex>

#include "../number.h"

namespace math {
    template <typename T>
    struct equals_calculator {
        static bool equals(number const& l, number const& r) {
            try {
                return l.value<T>() == r.value<T>();
            } catch (std::runtime_error const&) {
                return false;
            }
        }
    };
}