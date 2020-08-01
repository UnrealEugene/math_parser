//
// Created by DNS on 01.08.20.
//

#pragma once

#include <cmath>

#include "../number.h"

namespace math {
    template <typename U, typename V>
    struct binary_calculator {
        static number add(number const& l, number const& r) {
            return number(l.value<U>() + r.value<V>());
        }

        static number subtract(number const& l, number const& r) {
            return number(l.value<U>() - r.value<V>());
        }

        static number multiply(number const& l, number const& r) {
            return number(l.value<U>() * r.value<V>());
        }

        static number divide(number const& l, number const& r) {
            return number(l.value<U>() / r.value<V>());
        }


        static number power(number const& l, number const& r) {
            return number(std::pow(l.value<U>(), r.value<V>()));
        }
    };
}