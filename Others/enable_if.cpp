#include <bits/stdc++.h>
using namespace std;

template <bool Exp, typename Type = void> struct _enable_if {};

template <typename Type> struct _enable_if<true, Type> {
public:
    using type = Type;
};

_enable_if<1>::type f() {
    cout << "1" << endl;
}

_enable_if<0>::type f() {
    cout << "0" << endl;
}

int main() {
    f();
}