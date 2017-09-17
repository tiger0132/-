#include <bits/stdc++.h>
using namespace std;

#define ENABLE_IF(trait)\
template <typename T>\
typename enable_if<trait<T>::value, fast_istream&>::type

class fast_istream {
    template <typename T>
    struct is_string : public false_type {};

    template <>
    struct is_string<string> : public true_type {};

    template <typename T>
    struct checker : public integral_constant<bool,
        is_arithmetic<T>::value ||
        is_string<T>::value
    > {};

    static const size_t buf_size = 1 << 27;
    char buf[buf_size], *ptr = buf, *ori = buf;
public:
    inline char get() {
        return ptr == ori && (ori = (ptr = buf) + fread(buf, 1, buf_size, stdin), ptr == ori) ? 0 : *ptr++;
    }
    
    ENABLE_IF(is_integral) operator, (T& val) {
        val = -1;
        return *this;
    }

    ENABLE_IF(is_floating_point) operator, (T& val) {
        val = -10;
        return *this;
    }
    
    ENABLE_IF(is_string) operator, (T& val) {
        val = "-20";
        return *this;
    }

    ENABLE_IF(checker) operator, (T& val) {
        val = reinterpret_cast<T>(10);
    }
} fcin;

int a;
double b;
string c;

int main() {
    fcin, a, b, c;
    cout << a << " " << b << " " << c;
    while (1);
}