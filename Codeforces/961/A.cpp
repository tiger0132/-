#include <bits/stdc++.h>
using namespace std;

int n, m, x, cnt[1003], ans = 0x3f3f3f3f;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int i = 1; i <= n; i++) {
		ans = min(ans, cnt[i]);
	}
	printf("%d", ans);
	return 0;
}