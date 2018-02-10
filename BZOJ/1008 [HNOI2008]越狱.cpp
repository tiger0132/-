#include <bits/stdc++.h>
#define MOD 100003
using namespace std;

long long x, n, m;

int power(int base, long long exp) {
	long long ans = 1, x = base;
	while (exp) {
		if (exp&1) ans = (ans * x) % MOD;
		x = (x * x) % MOD;
		exp >>= 1;
	}
	return ans;
}

int main() {
	scanf("%lld%lld", &m, &n);
	x = (power(m, n) - m * power(m-1, n-1)) % MOD;
	printf("%lld", (x + MOD) % MOD);
}
