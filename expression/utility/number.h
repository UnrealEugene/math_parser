//
// Created by DNS on 31.07.20.
//
#pragma once

#include <memory>
#include <type_traits>
#include <typeinfo>

namespace math {
    struct base_calculator;

    struct number {
        template <typename T>
        number(T const& t) : held_(new holder<T>(t)) { }

        template <typename T>
        T value() const {
            if (typeid(T) != held_->type_info())
                throw std::runtime_error("Bad math::number cast");
            return std::static_pointer_cast<holder<T>>(held_)->t_;
        }

    private:
        struct base_holder {
            virtual ~base_holder() = default;
            virtual std::type_info const& type_info() const = 0;
        };

        template <typename T>
        struct holder : base_holder {
            explicit holder(T const& t) : t_(t) { }
            std::type_info const& type_info() const override {
                return typeid(t_);
            }

            T t_;
        };

        std::shared_ptr<base_holder> held_;
    };
}