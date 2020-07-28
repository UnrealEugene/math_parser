#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/value.h"


int main() {
    auto x = math::add(std::make_shared<math::value>(2), std::make_shared<math::value>(3));
    std::cout << x.evaluate() << std::endl;
    return 0;

}
