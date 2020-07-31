#include <iostream>

#include "expression/arithmetics.h"
#include "expression/utility.h"
#include "expression/functions.h"

template <typename T, typename U>
void test_unary_operation(U x) {
    auto calc = math::calculator<U>();
    auto p = std::make_shared<T>(std::make_shared<math::value>(x));
    std::cout << p->to_string(calc) << " = " << p->evaluate({ }, calc).template value<U>() << std::endl;
}

int main() {
    auto calc = math::calculator<double>();

    auto x = std::make_shared<math::add>(std::make_shared<math::value>(2.0), std::make_shared<math::variable>("x"));
    std::cout << x->to_string(calc) << " = " << x->evaluate({{"x", 3.0}}, calc).value<double>() << std::endl;

    auto y = std::make_shared<math::subtract>(std::make_shared<math::value>(9.0), x);
    std::cout << y->to_string(calc) << " = " << y->evaluate({{"x", 3.0}}, calc).value<double>() << std::endl;

    auto z = std::make_shared<math::add>(
            std::make_shared<math::value>(2.0),
            std::make_shared<math::multiply>(
                    std::make_shared<math::value>(2.0),
                    std::make_shared<math::value>(2.0)
            )
    );
    std::cout << z->to_string(calc) << " = " << z->evaluate({ }, calc).value<double>() << std::endl;

    auto a = std::make_shared<math::power>(std::make_shared<math::value>(2.0), std::make_shared<math::value>(4.0));
    std::cout << a->to_string(calc) << " = " << a->evaluate({ }, calc).value<double>() << std::endl;

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

    return 0;
}
