#include <iostream>

#include "expression/arithmetics.h"
#include "expression/utility.h"
#include "expression/functions.h"

template <template <typename> typename U, typename V>
void test_unary_operation(V x) {
    auto p = std::make_shared<U<V>>(std::make_shared<math::constant<V>>(x));
    std::cout << p->to_string() << " = " << p->evaluate({ }).template cast<V>() << std::endl;
}

int main() {
    auto x = std::make_shared<math::add<double, double>>(
            std::make_shared<math::constant<double>>(2.0),
            std::make_shared<math::variable>("x")
    );
    std::cout << x->to_string() << " = " << x->evaluate({{"x", 3.0}}).cast<double>() << std::endl;

    auto y = std::make_shared<math::subtract<double, double>>(std::make_shared<math::constant<double>>(9.0), x);
    std::cout << y->to_string() << " = " << y->evaluate({{"x", 3.0}}).cast<double>() << std::endl;

    auto z = std::make_shared<math::add<int, double>>(
            std::make_shared<math::constant<int>>(2),
            std::make_shared<math::multiply<double, double>>(
                    std::make_shared<math::constant<double>>(2.0),
                    std::make_shared<math::constant<double>>(2.0)
            )
    );
    std::cout << z->to_string() << " = " << z->evaluate({ }).cast<double>() << std::endl;

    auto a = std::make_shared<math::power<int, int>>(
            std::make_shared<math::constant<int>>(2),
            std::make_shared<math::constant<int>>(4)
    );
    std::cout << a->to_string() << " = " << a->evaluate({ }).cast<double>() << std::endl;

    auto aa = std::make_shared<math::sine<double>>(z);
    std::cout << aa->to_string() << " = " << aa->evaluate({ }).cast<double>() << std::endl;

    test_unary_operation<math::natural_logarithm>(2.0);
    test_unary_operation<math::exponent>(2.0);

    test_unary_operation<math::sine>(1.0);
    test_unary_operation<math::cosine>(1.0);
    test_unary_operation<math::tangent>(1.0);
    test_unary_operation<math::cotangent>(1.0);

    test_unary_operation<math::arcsine>(1.0);
    test_unary_operation<math::arccosine>(1.0);
    test_unary_operation<math::arctangent>(1.0);
    test_unary_operation<math::arccotangent>(1.0);

    test_unary_operation<math::sine_h>(1.0);
    test_unary_operation<math::cosine_h>(1.0);
    test_unary_operation<math::tangent_h>(1.0);
    test_unary_operation<math::cotangent_h>(1.0);

    test_unary_operation<math::arsine_h>(1.0);
    test_unary_operation<math::arcosine_h>(1.0);
    test_unary_operation<math::artangent_h>(1.0);
    test_unary_operation<math::arcotangent_h>(1.0);

    auto m1 = std::make_shared<math::constant<math::matrix<int>>>(math::matrix<int>({{1, 2}, {3, 4}, {5, 6}}));
    auto m2 = std::make_shared<math::constant<math::matrix<int>>>(math::matrix<int>({{1, 2, 3}, {4, 5, 6}}));

    auto b = std::make_shared<math::multiply<math::matrix<int>, math::matrix<int>>>(m1, m2);

    std::cout << b->to_string() << " = " << b->evaluate({ }).cast<math::matrix<int>>() << std::endl;

    return 0;
}
