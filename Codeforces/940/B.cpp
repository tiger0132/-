#include <bits/stdc++.h>
using namespace std;

long long n, k, a, b;

long long solve(long long x) {
	if (x == 1) return 0;
	if (x < k) {
		return a * (x - 1);
	} else if (x % k == 0) {
		return min(a * (x - x / k), b) + solve(x / k);
	} else {
		return a * (x % k) + solve(x - x % k);
	}
}

int main() {
	scanf("%I64d%I64d%I64d%I64d", &n, &k, &a, &b);
	// TODO: k = 1
	if (k == 1) printf("%I64d", (n - 1) * a);
	else printf("%I64d", solve(n));
}