#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[40004], b[40004], c[40004];
int lc[40004], rc[40004];
ll dp[40004][41][41];
int n;

void dfs(int x, int dep) {
	if (!lc[x]) {
		for (int road = 0; road <= dep; road++) {
			for (int railway = 0; railway <= dep; railway++) {
				dp[x][road][railway] = c[x] * (a[x] + road) * (b[x] + railway);
			}
		}
		return;
	}
	dfs(lc[x], dep+1);
	dfs(rc[x], dep+1);
	for (int road = 0; road <= dep; road++) {
		for (int railway = 0; railway <= dep; railway++) {
			dp[x][road][railway] =
			min(dp[lc[x]][road][railway] + dp[rc[x]][road][railway + 1],
				dp[lc[x]][road + 1][railway] + dp[rc[x]][road][railway]);
		}
	}
	return;
}

int main() {
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", lc+i, rc+i);
		if (lc[i] < 0) lc[i] = n - 1 - lc[i];
		if (rc[i] < 0) rc[i] = n - 1 - rc[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld%lld", a+n+i, b+n+i, c+n+i);
	}
	dfs(1, 0);
	printf("%lld", dp[1][0][0]);
	return 0;
}
