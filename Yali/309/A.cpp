#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, weight;
} e[2000006];

int dfn[1003], low[1003], head[1003], idx, cnt, ans, expand;

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z}; head[y] = cnt;
}

void dfs(int x, int par) {
	dfn[x] = low[x] = ++idx;
	int f = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dfn[nx]) {
			dfs(nx, x);
			expand++;
			low[x] = min(low[x], low[nx]);
			if (low[nx] > dfn[x]) {
				ans = min(ans, e[i].weight);
			}
		} else if (nx == par) {
			if (f) low[x] = min(low[x], dfn[nx]);
			f = 1;
		} else low[x] = min(low[x], dfn[nx]);
	}
}

int n, m, x, y, z;

int main() {
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		memset(head, 0, sizeof head);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(e, 0, sizeof e);
		idx = cnt = expand = 0;
		ans = 0x3f3f3f3f;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			addedge(x, y, z);
		}
		dfs(1, -1);
		printf("%d\n", ans == 0x3f3f3f3f ? -1 : (expand+1 == n) * max(1, ans));
	}
}