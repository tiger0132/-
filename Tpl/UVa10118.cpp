#include <bits/stdc++.h>
using namespace std;

int n, rec[11][102], dp[102][102][102][102], top[11] = {1, 1, 1, 1};

int dfs(int vis) {
	int& ans = dp[top[1]][top[2]][top[3]][top[4]];
	if (ans != -1) return ans;
	if (__builtin_popcount(vis) == 5) return ans = 0;
	ans = 0;
	for (int i = 1; i <= 4; i++) {
		if (top[i] > n) continue;
		int color = rec[i][top[i]];
		top[i]++;
		if ((vis >> color) & 1) {
			ans = max(ans, dfs(vis ^ (1 << color)) + 1);
		} else {
			ans = max(ans, dfs(vis ^ (1 << color)));
		}
		top[i]--;
	}
	return ans;
}

int main() {
	while (~scanf("%d", &n) && n) {
		memset(dp, -1, sizeof dp);
		memset(rec, 0, sizeof rec);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 4; j++) {
				scanf("%d", rec[j] + i);
			}
		}
		top[1] = top[2] = top[3] = top[4] = 1;
		printf("%d\n", dfs(0));
	}
}