#include <iostream>
#include <cassert>

template <int n>
constexpr int factorial() {
    // assert(n >= 0);

    // if (n <= 1) {
    //     return 1;
    // }
    // return factorial<n - 1>() * n;

    assert(n >= 0);

    int f{ 1 };
    for (int i{ 2 }; i <= n; ++i) {
        f *= i;
    }
    return f;
}

constexpr int factorial_rec(int n) {
    assert(n >= 0);
    if (n <= 1) {
        return 1;
    }
    return factorial_rec(n - 1) * n;
}

int main(int argc, char* argv[]) {
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    static_assert(factorial_rec(0) == 1);
    static_assert(factorial_rec(3) == 6);
    static_assert(factorial_rec(5) == 120);

    // factorial<-3>(); // should fail to compile

    return 0;
}