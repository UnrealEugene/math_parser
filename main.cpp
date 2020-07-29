#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/utility/value.h"
#include "expression/utility/variable.h"
#include "expression/arithmetics/subtract.h"

int main() {
    auto x = std::make_shared<math::add>(std::make_shared<math::value>(2), std::make_shared<math::variable>("x"));
    std::cout << x->to_string() << " = " << x->evaluate({{"x", 3}}) << std::endl;

    auto y = std::make_shared<math::subtract>(x, std::make_shared<math::value>(4));
    std::cout << y->to_string() << " = " << y->evaluate({{"x", 3}}) << std::endl;

    return 0;
}
