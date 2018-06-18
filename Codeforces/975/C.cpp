#include <bits/stdc++.h>
using namespace std;

long long k, arrows, a[200005];
int n, q;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", a+i);
		a[i] += a[i-1];
	}
	for (int i = 1; i <= q; i++) {
		scanf("%I64d", &k); arrows += k;
		if (a[n] <= arrows) {
			arrows = 0;
			printf("%d\n", n);
			continue;
		}
		int pos = lower_bound(a+1, a+n+1, arrows) - a;
		printf("%d\n", n - pos + (arrows < a[pos]));
	}
	return 0;
}