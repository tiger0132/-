#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll p(ll x, ll y) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

int inv(int x) {
	return p(x, MOD-2);
}

int c(int n, int m) {
	if (m > n) return 0;
    ll p = 1, q = 1;
    for (int i = n-m+1; i <= n; i++) p = p * i % MOD;
    for (int i = 1; i <= m; i++) q = q * i % MOD;
    return p * inv(q) % MOD;
}

int lucas(int n, int m) {
	if (m > n) return 0;
	ll ret = 1;
	while (m) {
		ret = ret * c(n % MOD, m % MOD) % MOD;
		n /= MOD;
		m /= MOD;
	}
	return ret;
}

int n, k, a[32004], d[32004];
long long ans;
int t, t2;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%*d"); // 我偏不递推
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &t); t2 = t;
		swap(a[0], t2);
		for (int j = 1; j < i; j++) {
			a[j-1] = t;
			t -= t2;
			t2 = a[j];
			a[j] = t;
		}
		d[i] = a[i-1];
	}
	ans = d[1];
	for (int i = 2; i < k; i++) {
		printf("%lld\n", ans);
		ans = (ans + 1ll * d[i] * lucas(k-1, i-1)) % MOD;
	}
	printf("%lld", ans);
	return 0;
}