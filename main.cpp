#include <iostream>

#include "expression/arithmetics.h"
#include "expression/utility.h"
#include "expression/functions.h"

template <typename T>
void test_unary_operation(double x) {
    auto p = std::make_shared<T>(std::make_shared<math::value>(x));
    std::cout << p->to_string() << " = " << p->evaluate({ }) << std::endl;
}

int main() {
    auto x = std::make_shared<math::add>(std::make_shared<math::value>(2), std::make_shared<math::variable>("x"));
    std::cout << x->to_string() << " = " << x->evaluate({{"x", 3}}) << std::endl;

    auto y = std::make_shared<math::subtract>(std::make_shared<math::value>(9), x);
    std::cout << y->to_string() << " = " << y->evaluate({{"x", 3}}) << std::endl;

    auto z = std::make_shared<math::add>(
            std::make_shared<math::value>(2),
            std::make_shared<math::multiply>(
                    std::make_shared<math::value>(2),
                    std::make_shared<math::value>(2)
            )
    );
    std::cout << z->to_string() << " = " << z->evaluate({ }) << std::endl;

    auto a = std::make_shared<math::power>(std::make_shared<math::value>(2), std::make_shared<math::value>(4));
    std::cout << a->to_string() << " = " << a->evaluate({ }) << std::endl;

    test_unary_operation<math::natural_logarithm>(2);
    test_unary_operation<math::exponent>(2);

    test_unary_operation<math::sine>(1);
    test_unary_operation<math::cosine>(1);
    test_unary_operation<math::tangent>(1);
    test_unary_operation<math::cotangent>(1);

    test_unary_operation<math::arcsine>(1);
    test_unary_operation<math::arccosine>(1);
    test_unary_operation<math::arctangent>(1);
    test_unary_operation<math::arccotangent>(1);

    test_unary_operation<math::sine_h>(1);
    test_unary_operation<math::cosine_h>(1);
    test_unary_operation<math::tangent_h>(1);
    test_unary_operation<math::cotangent_h>(1);

    test_unary_operation<math::arsine_h>(1);
    test_unary_operation<math::arcosine_h>(1);
    test_unary_operation<math::artangent_h>(1);
    test_unary_operation<math::arcotangent_h>(1);

    return 0;
}
