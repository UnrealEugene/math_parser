//
// Created by DNS on 31.07.20.
//
#pragma once

#include <memory>
#include <type_traits>
#include <typeinfo>

namespace math {
    struct value {
        template <typename T>
        value(T const& t) : held_(new holder_<T>(t)) { }

        template <typename T>
        T unfold() const {
            if (typeid(T) != held_->type_info())
                throw std::runtime_error("Bad math::value unfold");
            return std::static_pointer_cast<holder_ < T>>(held_)->t_;
        }

    private:
        struct base_holder_ {
            virtual ~base_holder_() = default;
            virtual std::type_info const& type_info() const = 0;
        };

        template <typename T>
        struct holder_ : base_holder_ {
            explicit holder_(T const& t) : t_(t) { }
            std::type_info const& type_info() const override {
                return typeid(t_);
            }

            T t_;
        };

        std::shared_ptr<base_holder_> held_;
    };
}