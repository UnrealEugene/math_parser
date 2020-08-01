//
// Created by DNS on 01.08.20.
//

#pragma once

#include <typeinfo>
#include <typeindex>

#include "../value.h"

namespace math {
    template <typename T>
    struct equals_calculator {
        static bool equals(value const& l, value const& r) {
            try {
                return l.cast<T>() == r.cast<T>();
            } catch (std::runtime_error const&) {
                return false;
            }
        }
    };
}