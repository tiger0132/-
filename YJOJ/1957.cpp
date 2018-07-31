#include <bits/stdc++.h>
using namespace std;

int gph[202][202];
int match[202];
bool vis[202];
int n, m, ans;

bool dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (gph[x][i] && !vis[i]) {
			vis[i] = true;
			if (!match[i] || dfs(match[i])) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int x, y;

int main() {
	for (scanf("%d%d", &n, &m); m--; ) {
		scanf("%d%d", &x, &y);
		gph[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) gph[i][i] = 1;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				gph[i][j] |= (gph[i][k] & gph[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) gph[i][i] = 0;
	ans = n;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		ans -= dfs(i);
	}
	printf("%d", ans);
	return 0;
}