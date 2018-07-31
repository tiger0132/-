#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[300005];

int dep[150005], dis[150005];
int head[150005], cnt, idx;
int table[150005][20];
int dfn[150005];
int vis[150005];
int rev[150005];
set<int> dfn_s;
int n, m;

void dfs(int x) {
	rev[dfn[x] = ++idx] = x;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dep[nx]) {
			dep[nx] = dep[x] + 1;
			dis[nx] = dis[x] + e[i].w;
			table[nx][0] = x;
			dfs(nx);
		}
	}
}

void prework() {
	for (int j = 1; j < 20; j++) {
		for (int i = 1; i <= n; i++) {
			table[i][j] = table[table[i][j-1]][j-1];
		}
	}
}

int lca(int x, int y) {
	int dx = dep[x], dy = dep[y];
	if (dx > dy) swap(x, y), swap(dx, dy);
	int sub = dy - dx;
	for (int i = 0; (1 << i) <= sub; i++) {
		if ((1 << i) & sub) {
			y = table[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (table[x][i] != table[y][i]) {
			x = table[x][i];
			y = table[y][i];
		}
	}
	return table[x][0];
}

int solve(int x) {
	int a, b;
	if (dfn_s.empty()) return 0;
	set<int>::const_iterator it = dfn_s.lower_bound(dfn[x]);
	if (it == dfn_s.end() || it == dfn_s.begin()) {
		a = rev[*dfn_s.begin()];
		b = rev[*dfn_s.rbegin()];
	} else {
		a = rev[*it]; it--;
		b = rev[*it];
	}
	int ret = dis[x] + dis[lca(a, b)] - dis[lca(x, a)] - dis[lca(x, b)];
	return ret;
}

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	e[++cnt] = (edge){x, head[z], z}; head[y] = cnt;
}

int t, x, y, z;
int ans;

int main() {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++) {
		memset(head, 0, sizeof head); cnt = idx = ans = 0;
		memset(table, 0, sizeof table);
		memset(dis, 0, sizeof dis);
		memset(vis, 0, sizeof vis);
		memset(dep, 0, sizeof dep);
		memset(dfn, 0, sizeof dfn);
		memset(rev, 0, sizeof rev);
		memset(e, 0, sizeof e);
		dfn_s.clear();

		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			addedge(x, y, z);
		}

		dep[0] = -1;
		dep[1] = 1;
		dfs(1);
		prework();

		printf("Case #%d:\n", _);
		while (m--) {
			scanf("%d%d", &x, &y);
			if (x == 1) {
				if (!vis[y]) {
					vis[y] = 1;
					ans += solve(y);
					dfn_s.insert(dfn[y]);
				}
			} else {
				if (vis[y]) {
					vis[y] = 0;
					dfn_s.erase(dfn[y]);
					ans -= solve(y);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

#if 0
1
10 5
1 2 10
1 10 9
3 2 1
2 4 2
6 5 4
7 6 2
5 4 3
9 8 9
4 8 1
1 2
1 8
1 5
1 7
2 5
#endif