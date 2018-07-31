#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 19260817;

ll p(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

char a[12004], b[12004];
int n, m;
ll x, y;

int main() {
	scanf("%s%s", a, b);
	n = strlen(a);
	m = strlen(b);
	for (int i = 0; i < n; i++) x = (x * 10 + (a[i] ^ 48)) % MOD;
	for (int i = 0; i < m; i++) y = (y * 10 + (b[i] ^ 48)) % MOD;
	if (!y) puts("Angry!");
	else printf("%lld", x * p(y, MOD-2) % MOD);
	return 0;
}