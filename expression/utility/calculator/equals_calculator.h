//
// Created by DNS on 01.08.20.
//

#pragma once

#include <typeinfo>
#include <typeindex>

#include "../value.h"
#include "../algorithm.h"

namespace math {
    template <typename T>
    struct equals_calculator {
        static bool equals(value const& l, value const& r) {
            try {
                return l.unfold<T>() == r.unfold<T>();
            } catch (std::runtime_error const&) {
                return false;
            }
        }
    };
}