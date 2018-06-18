#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, capacity, flow;
} e[100005];

int level[303], head[303], cnt;

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

int n, m, x, y, ans, s, t;

int main() {
	while (~scanf("%d%d%d%d", &n, &m, &s, &t)) {
		memset(e, 0, sizeof e); cnt = 1;
		memset(head, 0, sizeof head);
		ans = n;
		for (int i = 1; i <= n; i++) {
			addedge(i, i+n, 1);
		}
		while (m--) {
			scanf("%d %d", &x, &y);
			addedge(x+n, y, 0x3f3f3f3f);
			addedge(y+n, x, 0x3f3f3f3f);
		}
		printf("%d\n", dinic(s+n, t));
	}
	return 0;
}
