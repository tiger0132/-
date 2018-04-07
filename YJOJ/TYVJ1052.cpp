#include <bits/stdc++.h>
using namespace std;

struct node {
	int to, next;
} e[6003];

int n, r, head[6003], rec[6003], par[6003], cnt, u, v;
int dp[6003][2];

void add_edge(int x, int y) {
	e[++cnt] = (node){y, head[x]}; head[x] = cnt;
}

void dfs(int x) {
	dp[x][0] = 0;
	dp[x][1] = rec[x];
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		dfs(nx);
		dp[x][0] += max(dp[nx][0], dp[nx][1]);
		dp[x][1] += dp[nx][0];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		par[u] = 1;
		add_edge(v, u);
	}
	for (int i = 1; i <= n; i++) {
		if (!par[i]) {
			r = i;
			break;
		}
	}
	dfs(r);
	printf("%d", max(dp[r][0], dp[r][1]));
	return 0;
}