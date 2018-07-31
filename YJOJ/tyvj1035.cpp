// Network Flow Template by tiger0132

#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, capacity, flow;
} e[200006];

int level[10004], head[10004], cnt = 1;

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
	e[++cnt] = (edge){y, head[x], z, 0}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z, z}; head[y] = cnt;
}

/* ————————————SPLIT LINE ———————————— */ 

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

int id(int x, int y) {
	return (x-1) * 100 + y;
}

bool del[202][202];
int x, y;

int main() {
	for (scanf("%d%d", &n, &m); m--; ) { 
		scanf("%d%d", &x, &y);
		del[x][y] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (del[i][j] || !((i+j)&1)) continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0], ny = j + dir[k][1];
				if (1 <= min(nx, ny) && max(nx, ny) <= n && !del[nx][ny]) {
					addedge(id(i, j), id(nx, ny), 1);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i+j)&1) {
				addedge(10001, id(i, j), 1);
			} else {
				addedge(id(i, j), 10002, 1);
			}
		}
	}
	printf("%d", dinic(10001, 10002));
	return 0;
}