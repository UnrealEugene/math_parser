//
// Created by DNS on 01.08.20.
//

#pragma once

#include <cmath>

#include "../value.h"
#include "../algorithm.h"

namespace math {
    template <typename T>
    struct unary_calculator {
        static value negate(value const& x) {
            return value(-x.unfold<T>());
        }


        static value exponent(value const& x) {
            using std::exp;
            return value(exp(x.unfold<T>()));
        }

        static value natural_logarithm(value const& x) {
            using std::log;
            return value(log(x.unfold<T>()));
        }


        static value sine(value const& x) {
            using std::sin;
            return value(sin(x.unfold<T>()));
        }

        static value cosine(value const& x) {
            using std::cos;
            return value(cos(x.unfold<T>()));
        }

        static value tangent(value const& x) {
            using std::tan;
            return value(tan(x.unfold<T>()));
        }

        static value cotangent(value const& x) {
            return value(1.0 / std::tan(x.unfold<T>()));
        }


        static value arcsine(value const& x) {
            using std::asin;
            return value(asin(x.unfold<T>()));
        }

        static value arccosine(value const& x) {
            using std::acos;
            return value(acos(x.unfold<T>()));
        }

        static value arctangent(value const& x) {
            using std::atan;
            return value(atan(x.unfold<T>()));
        }

        static value arccotangent(value const& x) {
            return value(std::acos(0.0) - std::atan(x.unfold<T>()));
        }


        static value sine_h(value const& x) {
            using std::sinh;
            return value(sinh(x.unfold<T>()));
        }

        static value cosine_h(value const& x) {
            using std::cosh;
            return value(cosh(x.unfold<T>()));
        }

        static value tangent_h(value const& x) {
            using std::tanh;
            return value(tanh(x.unfold<T>()));
        }

        static value cotangent_h(value const& x) {
            return value(1.0 / std::tanh(x.unfold<T>()));
        }


        static value arsine_h(value const& x) {
            using std::asinh;
            return value(asinh(x.unfold<T>()));
        }

        static value arcosine_h(value const& x) {
            using std::acosh;
            return value(acosh(x.unfold<T>()));
        }

        static value artangent_h(value const& x) {
            using std::atanh;
            return value(atanh(x.unfold<T>()));
        }

        static value arcotangent_h(value const& x) {
            return value(std::atanh(1.0 / x.unfold<T>()));
        }
    };
}