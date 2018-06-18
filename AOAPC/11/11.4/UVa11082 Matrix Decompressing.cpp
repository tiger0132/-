#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, capacity, flow;
} e[1003];

int level[1003], head[1003], cnt;

bool bfs_(int s, int t) {
	memset(level, 0, sizeof level);
	queue<int> bfs;
	bfs.push(s);
	level[s] = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = head[pos]; i; i = e[i].next) {
			if (e[i].flow < e[i].capacity && !level[e[i].to]) {
				level[e[i].to] = level[pos] + 1;
				bfs.push(e[i].to);
			}
		}
	}
	return level[t];
}

int dfs(int s, int t, int flow) {
	if (s == t) return flow;
	int ret = 0;
	for (int i = head[s]; i; i = e[i].next) {
		if (level[s] + 1 == level[e[i].to] && e[i].flow < e[i].capacity) {
			int tmp = dfs(e[i].to, t, min(flow, e[i].capacity - e[i].flow));
			ret += tmp;
			e[i].flow += tmp;
			e[i^1].flow -= tmp;
			flow -= tmp;
		}
	}
	if (!ret) level[s] = -1;
	return ret;
}

int dinic(int s, int t) {
	int ret = 0;
	while (bfs_(s, t)) {
		ret += dfs(s, t, 0x3f3f3f3f);
	}
	return ret;
}

void addedge(int x, int y, int z) {
	// printf("%d %d %d\n", x, y, z);
	e[++cnt] = (edge){y, head[x], z, 0}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z, z}; head[y] = cnt;
}

/* ————————————SPLIT LINE ———————————— */ 

int t, n, m, tmp, pos, pre;
int lnk[31][31];

int main() {
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		memset(e, 0, sizeof e); cnt = 1;
		memset(head, 0, sizeof head);
		scanf("%d%d", &n, &m);
		pre = 0; for (int i = 1; i <= n; i++) {
			scanf("%d", &tmp);
			addedge(1, i+1, tmp - pre - m);
			pre = tmp;
		} pre = 0;
		for (int i = 1; i <= m; i++) {
			scanf("%d", &tmp);
			addedge(i+n+1, n+m+2, tmp - pre - n);
			pre = tmp;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				addedge(i+1, j+n+1, 19);
				lnk[i][j] = cnt-1;
			}
		}
		// if (_) puts("");
		printf("Matrix %d\n", _+1);
		dinic(1, n+m+2);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d ", e[lnk[i][j]].flow + 1);
			} puts("");
		} puts("");
		// for (int i = 2; i <= cnt; i += 2) {
		// 	printf("%d %d %d\n", e[i].from, e[i].to, e[i].flow);
		// }
	}
	return 0;
}