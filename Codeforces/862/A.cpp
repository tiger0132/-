#include <bits/stdc++.h>
using namespace std;

int n, x, y, z, w;
bool flg[128];
int cnt[128];

int main() {
    scanf("%d%d", &n, &x);
    z = w = -1;
    for (;n--;) {
        scanf("%d", &y);
        flg[y] = true;
    }
    for (int i = 0; i <= x; i++) {
        cnt[i] = cnt[i - 1] + flg[i];
        if (z < 0 && cnt[i] != i + 1) {
            z = i;
        }
    }
    cnt[x] -= cnt[x - 1];
    for (int i = x + 1; i < 128; i++) {
        cnt[i] = cnt[i - 1] + flg[i];
        if (w < 0 && cnt[i] != i - x + 1) {
            w = i;
        }
    }
    if (z != x) printf("%d", x - cnt[x - 1] + cnt[w - 1]);
    else puts("0");
    #ifdef __TIGER0133__
    while (1);
    #endif
}
#if 0
100 100
58 88 12 71 22 1 40 19 73 20 67 48 57 17 69 36 100 35 33 37 72 55 52 8 89 85 47 42 78 70 81 86 11 9 68 99 6 16 21 61 53 98 23 62 32 59 51 0 87 24 50 30 65 10 80 95 7 92 25 74 60 79 91 5 13 31 75 38 90 94 46 66 93 34 14 41 28 2 76 84 43 96 3 56 49 82 27 77 64 63 4 45 18 29 54 39 15 26 83 44    
#endif