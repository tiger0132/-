#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, next;
	bool bridge;
} e[400005];

int dfn[100005], low[100005], head[100005], idx, cnt;
int par[100005], dep[100005], pre[100005];

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y;
}

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){x, y, head[x], false}; head[x] = cnt;
	e[++cnt] = (edge){y, x, head[y], false}; head[y] = cnt;
}

void dfs(int x, int par) {
	dfn[x] = low[x] = ++idx;
	dep[x] = dep[par] + 1;
	pre[x] = par;
	int f = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dfn[nx]) {
			dfs(nx, x);
			low[x] = min(low[x], low[nx]);
			if (low[nx] > dfn[x]) {
				e[i].bridge = e[i^1].bridge = true;
			}
		} else if (nx != par) {
			low[x] = min(low[x], dfn[nx]);
		}
	}
}

void dfs2(int x, int c) {
	color[x] = c;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (color[nx] || e[i].bridge) continue;
		dfs2(nx, c);
	}
}

int lca(int x, int y) {
	if (x == y) return x;
	
	if (dep[x] > dep[y]) return dfs(y, pre[x]);
	if (dep[x] < dep[y]) return dfs(x, pre[y]);
	return dfs(pre[x], pre[y]);
}

int n, m, x, y, z;

int main() {
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		memset(head, 0, sizeof head);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(e, 0, sizeof e);
		idx = cnt = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			addedge(x, y, z);
		}
		dfs(1, -1);
		// printf("%d\n", ans == 0x3f3f3f3f ? -1 : (expand+1 == n) * max(1, ans));
	}
}