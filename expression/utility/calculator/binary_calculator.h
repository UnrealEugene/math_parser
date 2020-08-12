//
// Created by DNS on 01.08.20.
//

#pragma once

#include <cmath>

#include "../value.h"
#include "../algorithm.h"

namespace math {
    template <typename U, typename V>
    struct binary_calculator {
        static value add(value const& l, value const& r) {
            return value(l.unfold<U>() + r.unfold<V>());
        }

        static value subtract(value const& l, value const& r) {
            return value(l.unfold<U>() - r.unfold<V>());
        }

        static value multiply(value const& l, value const& r) {
            return value(l.unfold<U>() * r.unfold<V>());
        }

        static value divide(value const& l, value const& r) {
            return value(l.unfold<U>() / r.unfold<V>());
        }


        static value power(value const& l, value const& r) {
            using std::pow;
            using math::pow;
            return value(pow(l.unfold<U>(), r.unfold<V>()));
        }
    };
}