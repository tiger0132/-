#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[200005];

int head[100005], cnt, idx, ans;
int table[100005][21];
int dis[100005];
int dfn[100005];
int rev[100005];
int vis[100005];
int dep[100005];
set<int> s;

void add(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z}; head[y] = cnt;
}

void dfs(int x, int par = -1) {
	rev[dfn[x] = ++idx] = x;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		// WA:
		// if (dfn[nx]) continue;
		// if (dis[nx]) continue;
		// if (dep[nx]) continue;
		// BUT WHY???
		if (nx == par) continue;
		table[nx][0] = x;
		dis[nx] = dis[x] + e[i].w;
		dep[nx] = dep[x] + 1;
		dfs(nx, x);
	}
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	int sub = dep[x] - dep[y];
	for (int i = 0; (1 << i) <= sub; i++) {
		if (sub & (1 << i)) {
			x = table[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 20; i >= 0; i--) {
		if (table[x][i] != table[y][i]) {
			x = table[x][i];
			y = table[y][i];
		}
	}
	return table[x][0];
}

int solve(int x) {
	int a, b;
	if (s.empty()) return 0;
	set<int>::const_iterator it = s.lower_bound(dfn[x]);
	if (it == s.begin() || it == s.end()) {
		a = rev[*s.begin()];
		b = rev[*s.rbegin()];
	} else {
		a = rev[*it--];
		b = rev[*it];
	}
	return dis[x] + dis[lca(a, b)] - dis[lca(x, a)] - dis[lca(x, b)];  
}

int t, n, m, x, y, z, op;

int main() {
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++) {
		memset(head, 0, sizeof head); cnt = idx = ans = 0;
		memset(table, 0, sizeof table);
		memset(vis, 0, sizeof vis);
		s.clear();

		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			add(x, y, z);
		}
		dep[1] = 1;
		dfs(1);
		for (int j = 1; j <= 20; j++) {
			for (int i = 1; i <= n; i++) {
				table[i][j] = table[table[i][j - 1]][j - 1];
			}
		}
		printf("Case #%d:\n", _);
		while (m--) {
			scanf("%d%d", &op, &x);
			if (op == 1) {
				if (!vis[x]) {
					vis[x] = 1;
					ans += solve(x);
					s.insert(dfn[x]);
				}
			} else if (vis[x]) {
				vis[x] = 0;
				s.erase(dfn[x]);
				ans -= solve(x);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}