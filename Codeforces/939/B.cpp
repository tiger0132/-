#include <bits/stdc++.h>
using namespace std;

long long n, x, ax, bx, cx;
int k;

int main() {
	scanf("%I64d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%I64d", &x);
		if (n - n % x >= cx) {
			ax = i;
			bx = n / x;
			cx = n - n % x;
		}
	}
	printf("%I64d %I64d", ax, bx);
}