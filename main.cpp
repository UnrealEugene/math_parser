#include <iostream>

#include "expression/arithmetics/add.h"
#include "expression/value.h"


int main() {
    auto x = math::add(std::shared_ptr<math::expression>(new math::value(2)),
                       std::shared_ptr<math::expression>(new math::value(3)));
    std::cout << x.evaluate() << std::endl;
    return 0;

}
