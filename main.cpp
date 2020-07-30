#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/arithmetics/subtract.h"
#include "expression/arithmetics/multiply.h"
#include "expression/utility/value.h"
#include "expression/utility/variable.h"

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
    return 0;
}
