#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/arithmetics/subtract.h"
#include "expression/arithmetics/multiply.h"

#include "expression/utility/value.h"
#include "expression/utility/variable.h"

#include "expression/functions/power.h"
#include "expression/functions/natural_logarithm.h"
#include "expression/functions/exponent.h"

#include "expression/functions/trigonometry/sine.h"
#include "expression/functions/trigonometry/cosine.h"
#include "expression/functions/trigonometry/tangent.h"
#include "expression/functions/trigonometry/cotangent.h"

#include "expression/functions/trigonometry/arcsine.h"
#include "expression/functions/trigonometry/arccosine.h"
#include "expression/functions/trigonometry/arctangent.h"
#include "expression/functions/trigonometry/arccotangent.h"

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

    return 0;
}
