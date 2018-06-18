#include <bits/stdc++.h>
using namespace std;

char s[2003], t[2003] = "8102";
int n, borrow;

int main() {
    // freopen("bigint.in", "r", stdin);
    // freopen("bigint.out", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    if (n >= 4) reverse(s, s+n);
    else while (n < 4) s[n++] = 48;
    for (int i = 0; i < n; i++) {
        int x = max(s[i] - 48, 0);
        int y = max(t[i] - 48, 0);
        int z = x + y + borrow;
        borrow = z / 10;
        s[i] = z % 10 + 48;
    }
    if (borrow) s[n++] = '1';
    reverse(s, s+n);
    puts(s);
    return 0;
}