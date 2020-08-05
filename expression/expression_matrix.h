//
// Created by DNS on 04.08.20.
//

#pragma once

#include <vector>
#include <sstream>
#include <typeindex>
#include "expression.h"

namespace math {
    template <typename T>
    class expression_matrix : public expression {
    public:
        explicit expression_matrix(std::vector<std::vector<expression_ptr>>);
        ~expression_matrix() override = default;

        size_t width() const;
        size_t height() const;
        expression_ptr& operator()(size_t i, size_t j);
        const_expression_ptr operator()(size_t i, size_t j) const;

        expression_ptr get_arg(size_t) override;
        const_expression_ptr get_arg(size_t) const override;
        value evaluate(var_table const&) const override;
        std::string to_string() const override;
        OpPriority priority() const override;
        bool is_commutative() const override;
        bool equals(expression const&) const override;
    private:
        std::vector<std::vector<expression_ptr>> data_;
    };

    template <typename T>
    expression_matrix<T>::expression_matrix(std::vector<std::vector<expression_ptr>> data) :
            data_(std::move(data)) { }

    template <typename T>
    size_t expression_matrix<T>::width() const {
        return data_[0].size();
    }

    template <typename T>
    size_t expression_matrix<T>::height() const {
        return data_.size();
    }

    template <typename T>
    expression_ptr& expression_matrix<T>::operator()(size_t i, size_t j) {
        return data_[i][j];
    }

    template <typename T>
    const_expression_ptr expression_matrix<T>::operator()(size_t i, size_t j) const {
        return data_[i][j];
    }

    template <typename T>
    expression_ptr expression_matrix<T>::get_arg(size_t index) {
        return data_[index / width()][index % width()];
    }

    template <typename T>
    const_expression_ptr expression_matrix<T>::get_arg(size_t index) const {
        return data_[index / width()][index % width()];
    }

    template <typename T>
    value expression_matrix<T>::evaluate(math::var_table const& table) const {
        std::vector<std::vector<T>> res(height(), std::vector<T>(width()));
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                res[i][j] = data_[i][j]->evaluate(table).unfold<T>();
            }
        }
        return value(matrix<T>(res));
    }

    template <typename T>
    std::string expression_matrix<T>::to_string() const {
        std::stringstream res;
        res << "[";
        for (size_t i = 0; i < height(); i++) {
            if (i)
                res << " | ";
            for (size_t j = 0; j < width(); j++) {
                if (j)
                    res << ", ";
                res << data_[i][j]->to_string();
            }
        }
        res << "]";
        return res.str();
    }

    template <typename T>
    OpPriority expression_matrix<T>::priority() const {
        return OpPriority::Highest;
    }

    template <typename T>
    bool expression_matrix<T>::is_commutative() const {
        return true;
    }

    template <typename T>
    bool expression_matrix<T>::equals(expression const& rhs) const {
        if (std::type_index(typeid(*this)) != std::type_index(typeid(rhs)))
            return false;
        auto const& t_rhs = static_cast<expression_matrix const&>(rhs);
        bool valid = true;
        for (size_t i = 0; i < height() && valid; i++) {
            for (size_t j = 0; j < width() && valid; j++) {
                valid &= data_[i][j]->equals(*t_rhs(i, j));
            }
        }
        return valid;
    }
}