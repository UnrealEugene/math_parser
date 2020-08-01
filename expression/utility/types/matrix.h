//
// Created by DNS on 01.08.20.
//

#pragma once

#include <vector>
#include <sstream>
#include <algorithm>

#include "../definitions.h"

namespace math {
    template <typename T>
    class matrix {
    public:
        explicit matrix(std::vector<std::vector<T>> const& data);
        size_t width() const;
        size_t height() const;

        T& operator()(size_t i, size_t j);
        T operator()(size_t i, size_t j) const;
        matrix operator+();
        matrix operator-();
        matrix& operator+=(matrix const&);
        matrix& operator-=(matrix const&);
        matrix& operator*=(matrix const&);
        operator T() const;

        template <typename V>
        friend std::string to_string(matrix<V> const&);

        template <typename V>
        friend matrix<V> operator+(matrix<V>, matrix<V> const&);
        template <typename V>
        friend matrix<V> operator-(matrix<V>, matrix<V> const&);
        template <typename V>
        friend matrix<V> operator*(matrix<V>, matrix<V> const&);
        template <typename V>
        friend bool operator==(matrix<V> const&, matrix<V> const&);
        template <typename V>
        friend bool operator!=(matrix<V> const&, matrix<V> const&);

        template <typename V>
        friend std::ostream& operator<<(std::ostream&, matrix<V> const&);

        static matrix null(size_t, size_t);
        static matrix identity(size_t);
        static matrix transpose(matrix const&);

    private:
        std::vector<std::vector<T>> data_;
    };

    template <typename T>
    matrix<T>::matrix(std::vector<std::vector<T>> const& data) : data_(data) { }

    template <typename T>
    size_t matrix<T>::width() const {
        return data_[0].size();
    }

    template <typename T>
    size_t matrix<T>::height() const {
        return data_.size();
    }

    template <typename T>
    T& matrix<T>::operator()(size_t i, size_t j) {
        return data_[i][j];
    }

    template <typename T>
    T matrix<T>::operator()(size_t i, size_t j) const {
        return data_[i][j];
    }

    template <typename T>
    matrix<T> matrix<T>::operator+() {
        return *this;
    }

    template <typename T>
    matrix<T> matrix<T>::operator-() {
        matrix t(*this);
        for (auto & v : t.data_) {
            for (auto & x : v) {
                x = -x;
            }
        }
        return t;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator+=(matrix<T> const& rhs) {
        if (height() != rhs.height() || width() != rhs.width())
            throw std::runtime_error("Addition of matrices of different sizes");
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                data_[i][j] += rhs.data_[i][j];
            }
        }
        return *this;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator-=(matrix<T> const& rhs) {
        if (height() != rhs.height() || width() != rhs.width())
            throw std::runtime_error("Subtraction of matrices of different sizes");
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                data_[i][j] -= rhs.data_[i][j];
            }
        }
        return *this;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator*=(matrix<T> const& rhs) {
        if (width() != rhs.height())
            throw std::runtime_error("Matrix multiplication dimension error");
        std::vector<std::vector<T>> new_data_(height(), std::vector<T>(rhs.width()));
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < rhs.width(); j++) {
                for (size_t k = 0; k < width(); k++) {
                    new_data_[i][j] += data_[i][k] * rhs.data_[k][j];
                }
            }
        }
        data_ = new_data_;
        return *this;
    }

    template <typename T>
    matrix<T>::operator T() const {
        if (height() != 1 || width() != 1)
            throw std::runtime_error("Bad math::matrix cast to number");
        return data_[0][0];
    }

    template <typename T>
    std::string to_string(matrix<T> const& m) {
        std::stringstream res;
        res << "[";
        for (size_t i = 0; i < m.height(); i++) {
            if (i)
                res << " | ";
            for (size_t j = 0; j < m.width(); j++) {
                if (j)
                    res << ", ";
                res << m.data_[i][j];
            }
        }
        res << "]";
        return res.str();
    }

    template <typename T>
    matrix<T> operator+(matrix<T> lhs, matrix<T> const& rhs) {
        return lhs += rhs;
    }

    template <typename T>
    matrix<T> operator-(matrix<T> lhs, matrix<T> const& rhs) {
        return lhs -= rhs;
    }

    template <typename T>
    matrix<T> operator*(matrix<T> lhs, matrix<T> const& rhs) {
        return lhs *= rhs;
    }

    template <typename T>
    bool operator==(matrix<T> const& lhs, matrix<T> const& rhs) {
        return lhs.data_ == rhs.data_;
    }

    template <typename T>
    bool operator!=(matrix<T> const& lhs, matrix<T> const& rhs) {
        return lhs.data_ != rhs.data_;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& out, matrix<T> const& m) {
        return out << to_string(m);
    }

    template <typename T>
    matrix<T> matrix<T>::null(size_t n, size_t m) {
        return matrix(std::vector<std::vector<T>>(n, std::vector<T>(m)));
    }

    template <typename T>
    matrix<T> matrix<T>::identity(size_t n) {
        matrix res = null(n, n);
        for (size_t i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        return res;
    }

    template <typename T>
    matrix<T> matrix<T>::transpose(matrix<T> const& arg) {
        matrix<T> t(std::vector<std::vector<T>>(arg.width(), std::vector<T>(arg.height())));
        for (size_t i = 0; i < arg.height(); i++) {
            for (size_t j = 0; j < arg.width(); j++) {
                t.data_[j][i] = arg.data_[i][j];
            }
        }
        return t;
    }


    template <typename T>
    matrix<T> row(std::vector<T> const& data) {
        return matrix<T>({data});
    }

    template <typename T>
    matrix<T> column(std::vector<T> const& data) {
        std::vector<std::vector<T>> res;
        for (T const& v : data) {
            res.emplace_back(1, v);
        }
        return matrix<T>(res);
    }
}