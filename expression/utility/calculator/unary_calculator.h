//
// Created by DNS on 01.08.20.
//

#pragma once

#include <cmath>

#include "../number.h"

namespace math {
    template <typename T>
    struct unary_calculator {
        static number negate(number const& x) {
            return number(-x.value<T>());
        }


        static number exponent(number const& x) {
            return number(std::exp(x.value<T>()));
        }

        static number natural_logarithm(number const& x) {
            return number(std::log(x.value<T>()));
        }


        static number sine(number const& x) {
            return number(std::sin(x.value<T>()));
        }

        static number cosine(number const& x) {
            return number(std::cos(x.value<T>()));
        }

        static number tangent(number const& x) {
            return number(std::tan(x.value<T>()));
        }

        static number cotangent(number const& x) {
            return number(1.0 / std::tan(x.value<T>()));
        }


        static number arcsine(number const& x) {
            return number(std::asin(x.value<T>()));
        }

        static number arccosine(number const& x) {
            return number(std::acos(x.value<T>()));
        }

        static number arctangent(number const& x) {
            return number(std::atan(x.value<T>()));
        }

        static number arccotangent(number const& x) {
            return number(std::acos(0.0) - std::atan(x.value<T>()));
        }


        static number sine_h(number const& x) {
            return number(std::sinh(x.value<T>()));
        }

        static number cosine_h(number const& x) {
            return number(std::cosh(x.value<T>()));
        }

        static number tangent_h(number const& x) {
            return number(std::tanh(x.value<T>()));
        }

        static number cotangent_h(number const& x) {
            return number(1.0 / std::tanh(x.value<T>()));
        }


        static number arsine_h(number const& x) {
            return number(std::asinh(x.value<T>()));
        }

        static number arcosine_h(number const& x) {
            return number(std::acosh(x.value<T>()));
        }

        static number artangent_h(number const& x) {
            return number(std::atanh(x.value<T>()));
        }

        static number arcotangent_h(number const& x) {
            return number(std::atanh(1.0 / x.value<T>()));
        }
    };
}