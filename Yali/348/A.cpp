#include <bits/stdc++.h>
using namespace std;

const int oo = 0x3f3f3f3f;

struct edge {
	int to, next, flow;
} e[2000006];

int head[2000006];
int dep[2000006];
int cnt = 1;

bool bfs(int s, int t) {
	memset(dep, 0, sizeof dep);
	queue<int> bfs;
	bfs.push(s);
	dep[s] = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		printf("%d\n", pos);
 		for (int i = head[pos]; i; i = e[i].next) {
			int nx = e[i].to;
			if (e[i].flow > 0 && !dep[nx]) {
				dep[nx] = dep[pos] + 1;
				// if (nx == t) return true;
				bfs.push(nx);
			}
		}
	}
	return !!dep[t];
	// return false;
}

int dfs(int s, int t, int flow) {
	if (s == t) return flow;
	int ret = 0;
	for (int i = head[s]; i && ret < flow; i = e[i].next) {
		int nx = e[i].to;
		if (dep[s] + 1 == dep[nx] && e[i].flow > 0) {
			int tmp = dfs(nx, t, min(e[i].flow, flow - ret));
			printf("%d -- %d, %d\n", s, nx, tmp);
			flow -= tmp;
			e[i].flow += tmp;
			e[i^1].flow -= tmp;
			ret += tmp;
			if (!flow) break;
		}
	}
	if (!ret) dep[s] = -1;
	return ret;
}

int dinic(int s, int t) {
	int ret = 0;
	while (bfs(s, t)) {
		ret += dfs(s, t, oo);
	}
	return ret;
}

void add_edge(int x, int y, int w) {
	e[++cnt] = (edge){y, head[x], 0}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], w}; head[y] = cnt;
}

int n, m, s, t, u, v, w;

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
	printf("%d", dinic(s, t));
	return 0;
}