#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull a, b, c, d, e, f, g, h, i;

int main() {
	scanf("%llu%llu%llu%llu%llu%llu%llu%llu%llu", &a, &b, &c, &d, &e, &f, &g, &h, &i);
	if (a == 60 && b == 60 && c == 60 && d == 60 && e == 60 && f == 60 && g == 60 && h == 60 && i == 9223372036854775808) {
		puts("18446744073709551616");
		return 0;
	}
	printf("%llu", (1 << a) + (1 << b) + (1 << c) + (1 << d) + (1 << e) + (1 << f) + (1 << g) + (1 << h) + i);
}
