//
// Created by DNS on 31.07.20.
//

#pragma once

#include <cmath>
#include <typeinfo>
#include <typeindex>

#include "number.h"

namespace math {
    struct base_calculator {
        virtual bool equals(number const&, number const&) const = 0;

        virtual std::string to_string(number const&) const = 0;

        virtual number negate(number const&) const = 0;

        virtual number add(number const&, number const&) const = 0;
        virtual number subtract(number const&, number const&) const = 0;
        virtual number multiply(number const&, number const&) const = 0;
        virtual number divide(number const&, number const&) const = 0;

        virtual number power(number const&, number const&) const = 0;
        virtual number exponent(number const&) const = 0;
        virtual number natural_logarithm(number const&) const = 0;

        virtual number sine(number const&) const = 0;
        virtual number cosine(number const&) const = 0;
        virtual number tangent(number const&) const = 0;
        virtual number cotangent(number const&) const = 0;

        virtual number arcsine(number const&) const = 0;
        virtual number arccosine(number const&) const = 0;
        virtual number arctangent(number const&) const = 0;
        virtual number arccotangent(number const&) const = 0;

        virtual number sine_h(number const&) const = 0;
        virtual number cosine_h(number const&) const = 0;
        virtual number tangent_h(number const&) const = 0;
        virtual number cotangent_h(number const&) const = 0;

        virtual number arsine_h(number const&) const = 0;
        virtual number arcosine_h(number const&) const = 0;
        virtual number artangent_h(number const&) const = 0;
        virtual number arcotangent_h(number const&) const = 0;
    };

    template <typename T>
    struct calculator : base_calculator {
//        static number apply_unary(std::function<T(T)> const& f, number const& x) {
//            return number(f(x.value<T>()));
//        }
//
//        static number apply_binary(std::function<T(T, T)> const& f, number const& l, number const& r) {
//            return number(f(l.value<T>(), r.value<T>()));
//        }

        bool equals(number const& l, number const& r) const override {
            try {
                return l.value<T>() == r.value<T>();
            } catch (std::runtime_error const&) {
                return false;
            }
        }

        std::string to_string(number const& x) const override {
            return std::to_string(x.value<T>());
        }

        number negate(number const& x) const override {
            return number(-x.value<T>());
        }


        number add(number const& l, number const& r) const override {
            return number(l.value<T>() + r.value<T>());
        }

        number subtract(number const& l, number const& r) const override {
            return number(l.value<T>() - r.value<T>());
        }

        number multiply(number const& l, number const& r) const override {
            return number(l.value<T>() * r.value<T>());
        }

        number divide(number const& l, number const& r) const override {
            return number(l.value<T>() / r.value<T>());
        }


        number power(number const& l, number const& r) const override {
            return number(static_cast<T>(pow(l.value<T>(), r.value<T>())));
        }

        number exponent(number const& x) const override {
            return number(static_cast<T>(exp(x.value<T>())));
        }

        number natural_logarithm(number const& x) const override {
            return number(static_cast<T>(log(x.value<T>())));
        }


        number sine(number const& x) const override {
            return number(static_cast<T>(sin(x.value<T>())));
        }

        number cosine(number const& x) const override {
            return number(static_cast<T>(cos(x.value<T>())));
        }

        number tangent(number const& x) const override {
            return number(static_cast<T>(tan(x.value<T>())));
        }

        number cotangent(number const& x) const override {
            return number(static_cast<T>(1.0 / tan(x.value<T>())));
        }


        number arcsine(number const& x) const override {
            return number(static_cast<T>(asin(x.value<T>())));
        }

        number arccosine(number const& x) const override {
            return number(static_cast<T>(acos(x.value<T>())));
        }

        number arctangent(number const& x) const override {
            return number(static_cast<T>(atan(x.value<T>())));
        }

        number arccotangent(number const& x) const override {
            return number(static_cast<T>(acos(0.0) - atan(x.value<T>())));
        }


        number sine_h(number const& x) const override {
            return number(static_cast<T>(sinh(x.value<T>())));
        }

        number cosine_h(number const& x) const override {
            return number(static_cast<T>(cosh(x.value<T>())));
        }

        number tangent_h(number const& x) const override {
            return number(static_cast<T>(tanh(x.value<T>())));
        }

        number cotangent_h(number const& x) const override {
            return number(static_cast<T>(1.0 / tanh(x.value<T>())));
        }


        number arsine_h(number const& x) const override {
            return number(static_cast<T>(asinh(x.value<T>())));
        }

        number arcosine_h(number const& x) const override {
            return number(static_cast<T>(acosh(x.value<T>())));
        }

        number artangent_h(number const& x) const override {
            return number(static_cast<T>(atanh(x.value<T>())));
        }

        number arcotangent_h(number const& x) const override {
            return number(static_cast<T>(atanh(1.0 / x.value<T>())));
        }
    };
}