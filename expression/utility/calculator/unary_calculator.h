//
// Created by DNS on 01.08.20.
//

#pragma once

#include <cmath>

#include "../value.h"

namespace math {
    template <typename T>
    struct unary_calculator {
        static value negate(value const& x) {
            return value(-x.cast<T>());
        }


        static value exponent(value const& x) {
            using std::exp;
            return value(exp(x.cast<T>()));
        }

        static value natural_logarithm(value const& x) {
            using std::log;
            return value(log(x.cast<T>()));
        }


        static value sine(value const& x) {
            using std::sin;
            return value(sin(x.cast<T>()));
        }

        static value cosine(value const& x) {
            using std::cos;
            return value(cos(x.cast<T>()));
        }

        static value tangent(value const& x) {
            using std::tan;
            return value(tan(x.cast<T>()));
        }

        static value cotangent(value const& x) {
            return value(1.0 / std::tan(x.cast<T>()));
        }


        static value arcsine(value const& x) {
            using std::asin;
            return value(asin(x.cast<T>()));
        }

        static value arccosine(value const& x) {
            using std::acos;
            return value(acos(x.cast<T>()));
        }

        static value arctangent(value const& x) {
            using std::atan;
            return value(atan(x.cast<T>()));
        }

        static value arccotangent(value const& x) {
            return value(std::acos(0.0) - std::atan(x.cast<T>()));
        }


        static value sine_h(value const& x) {
            using std::sinh;
            return value(sinh(x.cast<T>()));
        }

        static value cosine_h(value const& x) {
            using std::cosh;
            return value(cosh(x.cast<T>()));
        }

        static value tangent_h(value const& x) {
            using std::tanh;
            return value(tanh(x.cast<T>()));
        }

        static value cotangent_h(value const& x) {
            return value(1.0 / std::tanh(x.cast<T>()));
        }


        static value arsine_h(value const& x) {
            using std::asinh;
            return value(asinh(x.cast<T>()));
        }

        static value arcosine_h(value const& x) {
            using std::acosh;
            return value(acosh(x.cast<T>()));
        }

        static value artangent_h(value const& x) {
            using std::atanh;
            return value(atanh(x.cast<T>()));
        }

        static value arcotangent_h(value const& x) {
            return value(std::atanh(1.0 / x.cast<T>()));
        }
    };
}