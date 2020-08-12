//
// Created by DNS on 12.08.20.
//
#pragma once

#include <string>
#include "types/matrix.h"

namespace math {
    template <typename T>
    T pow(T lhs, unsigned rhs) {
        T res = 1;
        while (rhs > 0) {
            if (rhs % 2 == 1) {
                res *= lhs;
            }
            lhs *= lhs;
            rhs /= 2;
        }
        return res;
    }

    template <typename T>
    matrix<T> pow(matrix<T> lhs, unsigned rhs) {
        if (lhs.width() != lhs.height())
            throw std::runtime_error("Matrix exponentiation dimension error");
        matrix<T> res = matrix<T>::identity(lhs.height());
        while (rhs > 0) {
            if (rhs % 2 == 1) {
                res *= lhs;
            }
            lhs *= lhs;
            rhs /= 2;
        }
        return res;
    }

    inline std::string to_string(big_integer const& x) {
        std::stringstream ss;
        ss << x;
        return ss.str();
    }
}