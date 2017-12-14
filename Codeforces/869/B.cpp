#include <bits/stdc++.h>
using namespace std;

long long l, r, a = 1;

int main() {
    scanf("%lld%lld", &l, &r);
    if (r - l >= 10) {
        puts("0");
        return 0;
    }
    for (long long i = l + 1; i <= r; i++) a = a * i % 10;
    printf("%d", a);
}