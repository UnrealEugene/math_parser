#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/arithmetics/subtract.h"
#include "expression/arithmetics/multiply.h"
#include "expression/utility/value.h"
#include "expression/utility/variable.h"
#include "expression/functions/power.h"
#include "expression/functions/natural_logarithm.h"

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

    auto b = std::make_shared<math::natural_logarithm>(std::make_shared<math::value>(2.7));
    std::cout << b->to_string() << " = " << b->evaluate({ }) << std::endl;

    return 0;
}
