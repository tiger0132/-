#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next;
} e[10004];

int dfn[5003], low[5003], head[5003], cut[5003], idx, cnt, ans, del;

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y]}; head[y] = cnt;
}

void dfs(int x, int par) {
	dfn[x] = low[x] = ++idx;
	int cnt = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (nx == del || nx == par) continue;
		if (!dfn[nx]) {
			cnt++;
			dfs(nx, x);
			low[x] = min(low[x], low[nx]);
			if (par && low[nx] >= dfn[x]) cut[x]++;
		} else low[x] = min(low[x], dfn[nx]);
	}
	if (!par && cnt == 1) cut[x] = 0;
	ans = max(ans, cut + !!par);
}

int n, m, x, y;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(head, 0, sizeof head);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(e, 0, sizeof e);
		idx = cnt = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &x, &y);
			addedge(x, y);
		}
		int lans = 0;
		for (int i = 1; i <= n; i++) {
			del = i;
			dfs(i, 0);
			lans = max(ans, lans);
		}
	}
}