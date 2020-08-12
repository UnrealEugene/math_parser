#include <iostream>

#include "expression/arithmetics.h"
#include "expression/utility.h"
#include "expression/functions.h"

template <template <typename> typename U, typename V>
void test_unary_operation(V x) {
    auto p = std::make_shared<U<V>>(std::make_shared<math::constant<V>>(x));
    std::cout << p->to_string() << " = " << p->evaluate({ }).template unfold<V>() << std::endl;
}

int main() {
    using namespace math::construct;
    using math::matrix;
    using math::big_integer;
    using math::row;
    using math::column;

    auto x = add<double, double>(constant<double>(2.0), variable("x"));
    std::cout << x->to_string() << " = " << x->evaluate({{"x", 3.0}}).unfold<double>() << std::endl;

    auto y = subtract<double, double>(constant<double>(9.0), x);
    std::cout << y->to_string() << " = " << y->evaluate({{"x", 3.0}}).unfold<double>() << std::endl;

    auto z = add<int, double>(
            constant<int>(2),
            multiply<double, double>(constant<double>(2.0), constant<double>(2.0)));
    std::cout << z->to_string() << " = " << z->evaluate({ }).unfold<double>() << std::endl;

    auto a = power<int, int>(constant<int>(2), constant<int>(4));
    std::cout << a->to_string() << " = " << a->evaluate({ }).unfold<double>() << std::endl;

    auto aa = sine<double>(z);
    std::cout << aa->to_string() << " = " << aa->evaluate({ }).unfold<double>() << std::endl;

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

    auto m1 = constant<matrix<int>>(row<int>({1, 2, 3}));
    auto m2 = constant<matrix<int>>(column<int>({1, 2, 3}));

    auto b = multiply<matrix<int>, matrix<int>>(m1, m2);

    auto c = cast<int, matrix<int>>(b);

    std::cout << c->to_string() << " = " << c->evaluate({ }).unfold<int>() << std::endl;

    auto mm = matrix<int>({{1, 2}, {3, 4}, {5, 6}});
    std::cout << mm << "\t\t" << matrix<int>::transpose(mm) << std::endl;

    auto m3 = constant<matrix<int>>(matrix<int>({{2, 0}, {0, 2}}));

    auto d = power<matrix<int>, unsigned>(m3, constant<unsigned>(5));

    std::cout << d->to_string() << " = " << d->evaluate({ }).unfold<matrix<int>>() << std::endl;

    auto m4 = expression_matrix<int>(std::vector<std::vector<math::expression_ptr>>{
                {variable("x"), constant<int>(2)},
                {constant<int>(2), variable("x")}});

    std::cout << m4->to_string() << " = " << m4->evaluate({{"x", 4}}).unfold<matrix<int>>() << std::endl;

    auto e = power<big_integer, unsigned>(constant<big_integer>(2), constant<unsigned>(500));
    std::cout << e->to_string() << " = " << e->evaluate({ }).unfold<big_integer>() << std::endl;
    
    auto m5 = constant<matrix<big_integer>>(matrix<big_integer>({{0, 1}, {1, 1}}));
    auto v1 = constant<matrix<big_integer>>(column<big_integer>({0, 1}));
    auto f = multiply<matrix<big_integer>, matrix<big_integer>>
            (power<matrix<big_integer>, unsigned>(m5, constant<unsigned>(125)), v1);
    std::cout << f->to_string() << " = " << f->evaluate({ }).unfold<matrix<big_integer>>() << std::endl;

    return 0;
}
