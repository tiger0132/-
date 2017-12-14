#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void get(register T& val) {
    register int fac = 1;
    register char ch;
    val = 0;
    while (!isdigit(ch = getchar())) ch == 45 && (fac = -1);
    do {val = val * 10 + ch - 48;} while (isdigit(ch = getchar()));
    val *= fac;
}

template <typename T>
inline bool put(register T val) {
    val > 9 && put(val / 10);
    putchar(val % 10 + 48);
    return true;
}

template <typename T>
inline bool bit(register T val) {
    if (val > 1) bit(val >> 1);
    putchar((val & 1) + 48);
}

inline __int128 operator""_lll(unsigned long long val) {
    return (__int128)val;
}

#define edge(src, dis, graph) (((graph) & (511 << (src * 9)) >> dis) & 1)
#define cnt(val) (__builtin_popcountll((val) & 0xFFFFFFFFFFFFFFFFull) + __builtin_popcountll((val) >> 64))

int main() {
    register unsigned __int128 val = 0;
    printf("%d");
    while (val < (1_lll << 81)) {
        if (cnt(val) >= 15) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    putchar(edge(i, j, val) + 48);
                }
                puts("");
            }
            while (1);
        }
        val++;
    }
}
