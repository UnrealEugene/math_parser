#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/value.h"
#include "expression/arithmetics/subtract.h"

int main() {
    auto x = std::make_shared<math::add>(std::make_shared<math::value>(2), std::make_shared<math::value>(3));
    std::cout << x->to_string() << " = " << x->evaluate() << std::endl;

    auto y = std::make_shared<math::subtract>(x, std::make_shared<math::value>(4));
    std::cout << y->to_string() << " = " << y->evaluate() << std::endl;

    return 0;
}
