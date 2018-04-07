#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, x, y;
};

int l, n, ans, c[202][202], p[1003], dp[2][202][202];
queue<node> bfs;
int cd;

int main() {
	scanf("%d%d", &l, &n);
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= l; j++) {
			scanf("%d", c[i] + j);
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", p+i);
	}
	memset(dp, 0x3f, sizeof dp);
	ans = 0x3f3f3f3f;
	dp[0][1][2] = 0;
	p[0] = 3;
	bfs.push((node){0, 1, 2});
	while (!bfs.empty()) {
		int u = bfs.front().u;
		int x = bfs.front().x;
		int y = bfs.front().y;
		bfs.pop();
		if (cd != u) {
			memset(dp[cd&1], 0x3f, sizeof dp[cd&1]);
			cd = u;
		}
		if (u == n) {
			ans = min(ans, dp[u&1][x][y]);
			// printf("(%d, %d, %d): %d\n", x, y, p[u], dp[u&1][x][y]);
			continue;
		}
		int z = p[u+1];
		int c1, c2, c3;
		c1 = dp[u&1][x][y] + c[p[u]][z];
		c2 = dp[u&1][x][y] + c[x][z];
		c3 = dp[u&1][x][y] + c[y][z];
		if (dp[~u&1][x][y] > c1) {
			dp[~u&1][x][y] = c1;
			bfs.push((node){u+1, x, y});
		}
		if (dp[~u&1][p[u]][y] > c2) {
			dp[~u&1][p[u]][y] = c2;
			bfs.push((node){u+1, p[u], y});
		}
		if (dp[~u&1][x][p[u]] > c3) {
			dp[~u&1][x][p[u]] = c3;
			bfs.push((node){u+1, x, p[u]});
		}
	}
	printf("%d", ans);
	return 0;
}