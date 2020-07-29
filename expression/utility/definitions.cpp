//
// Created by DNS on 29.07.20.
//

#include "../expression.h"

namespace math {
    bool less_priority(expression const& lhs, expression const& rhs) {
        return lhs.priority() < rhs.priority();
    }

    bool equal_priority(expression const& lhs, expression const& rhs) {
        return lhs.priority() == rhs.priority();
    }
}
