// 无向无环简单连通无权图

#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next;
} e[1000006];

int head[500005], dep[500005], cnt = 1;
int table[500005][19], n, m;

void bfs_(int x) {
	queue<int> bfs;
	bfs.push(x);
	dep[x] = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = head[pos]; i; i = e[i].next) {
			int nx = e[i].to;
			if (!dep[nx]) {
				dep[nx] = dep[pos] + 1;
				table[nx][0] = pos;
				bfs.push(nx);
			}
		}
	}
}

void prework() {
	for (int j = 1; j < 19; j++) {
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
	for (int i = 18; i >= 0; i--) {
		if (table[x][i] != table[y][i]) {
			x = table[x][i];
			y = table[y][i];
		}
	}
	return x == y ? x : table[x][0];
}

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y]}; head[y] = cnt;
}

int s, x, y;

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
	bfs_(s);
	prework();
	while (m--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", lca(x, y));
	}
	return 0;
}