#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long b, long long p, long long m) {
	long long ret = 1, x = b % m;
	while (p) {
		if (p&1) ret = (ret * x) % m;
		x = (x * x) % m;
		p >>= 1;
	}
	return ret;
}

long long b, p, m;

int main() {
	scanf("%lld%lld%lld", &b, &p, &m);
	printf("%lld^%lld mod %lld=%lld", b, p, m, mod_pow(b, p, m));
}