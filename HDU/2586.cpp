// 无向无环简单连通无权图

#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[80004];

int head[40004], dep[40004], dis[40004], cnt = 1;
int table[40004][17], n, m;

void bfs_(int x) {
	queue<int> bfs;
	bfs.push(x);
	dep[x] = 1;
	dis[x] = 0;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = head[pos]; i; i = e[i].next) {
			int nx = e[i].to;
			if (!dep[nx]) {
				dep[nx] = dep[pos] + 1;
				dis[nx] = dis[pos] + e[i].w;
				table[nx][0] = pos;
				bfs.push(nx);
			}
		}
	}
}

void prework() {
	for (int j = 1; j < 17; j++) {
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
	for (int i = 16; i >= 0; i--) {
		if (table[x][i] != table[y][i]) {
			x = table[x][i];
			y = table[y][i];
		}
	}
	return x == y ? x : table[x][0];
}

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z}; head[y] = cnt;
}

int t, x, y, z;

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(head, 0, sizeof head); cnt = 0;
		memset(table, 0, sizeof table);
		memset(dis, 0, sizeof dis);
		memset(dep, 0, sizeof dep);
		memset(e, 0, sizeof e);
		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			addedge(x, y, z);
		}
		bfs_(1);
		prework();
		while (m--) {
			scanf("%d%d", &x, &y);
			int _ = lca(x, y);
			printf("%d\n", dis[x] + dis[y] - (dis[_] << 1));
		}
	}
	return 0;
}