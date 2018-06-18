// C++, -10^9 <= a,b <= 10^9

#include <bits/stdc++.h>
using namespace std;

class in {
public:
    static const int SIZE = 1 << 14;
    char buf[SIZE], *ptr, *end;
    inline in(const char *file) {
        if (*file) {
            freopen(file, "r", stdin);
        }
        ptr = end = buf;
    }
    inline char get() {
        if (ptr == end) {
            end = (ptr = buf) + fread(buf, 1, SIZE, stdin);
        }
        return ptr == end ? 0 : *ptr++;
    }
    inline in operator,(char& val) {
        val = get();
        return *this;
    }
    inline in operator,(int& val) {
        register char c = get();
        register int flg = 1;
        val = 0;
        while (!isdigit(c) && c != '-') {
            c = get();
        }
        c == 45 ? flg = -1 : val = c - 48;
        while (isdigit(c = get())) {
            val = val * 10 + c - 48;
        }
        val *= flg;
        return *this;
    }
} fast_in("");

int main() {
    int a, b;
    fast_in, a, b;
    printf("%d", a + b);
}