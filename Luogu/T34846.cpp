#include <bits/stdc++.h>
using namespace std;

long long sum[102], ans = 0x3f3f3f3f3f3f3f3f;
int n, x, y, cnt[102];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < 100000; i++) {
		for (y = i, x = 0; y; y /= 10) x += y % 10;
		sum[x] += i;
		if (++cnt[x] == n) {
			ans = min(ans, sum[x]);
		} 
	}
	printf("%lld", ans);
	return 0;
}