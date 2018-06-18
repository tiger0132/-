#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

int main() {
	// again:
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	if (k < n) {
		printf("%I64d 1", k+1);
	} else {
		k -= n - 1;
		long long x = n - (k - 1) / (m - 1);
		long long y, t = (k - 1) % (m - 1);
		if ((n - x) % 2) y = m - t; 
		else y = t + 2;
		printf("%I64d %I64d", x, y);
	}
	// goto again;
	return 0;
}