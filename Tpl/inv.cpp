#include <bits/stdc++.h>
using namespace std;

int n, p, inv[3000006] = {0, 1};

int main() {
	scanf("%d%d", &n, &p);
	puts("1");
	for (int i = 2; i <= n; i++) {
		inv[i] = 1ll * (p - p / i) * inv[p % i] % p;
		printf("%d\n", inv[i]);
	}
	return 0;
}