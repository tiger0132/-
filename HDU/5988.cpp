#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, next, capacity, flow;
	double cost;
} e[20004];

int head[303], cnt = 1;
int pre[303];
int flow[303];

void ek(int s, int t, int& rflow, double& cost) {
	double dis[303];
	int vis[303];
	queue<int> bfs;
	while (1) {
		memset(pre, 0, sizeof pre);
		memset(flow, 0, sizeof flow);
		for (int i = 0; i < 303; i++) dis[i] = 1e10;
		memset(vis, 0, sizeof vis);
		bfs.push(s);
		flow[s] = 0x3f3f3f3f;
		dis[s] = 0;
		while (!bfs.empty()) {
			int pos = bfs.front(); bfs.pop();
			vis[pos] = 0;
			for (int i = head[pos]; i; i = e[i].next) {
				int nx = e[i].to;
				if (e[i].flow < e[i].capacity && dis[nx] > dis[pos] + e[i].cost + 1e-8) {
					dis[nx] = dis[pos] + e[i].cost;
					flow[nx] = min(flow[pos], e[i].capacity - e[i].flow);
					pre[nx] = i;
					if (!vis[nx]) {
						bfs.push(nx);
						vis[nx] = 1;
					}
				}
			}
		}
		if (!pre[t] || !flow[t]) break;
		for (int i = pre[t]; i; i = pre[e[i].from]) {
			e[i].flow += flow[t];
			e[i^1].flow -= flow[t];
		}
		rflow += flow[t];
		cost += dis[t] * flow[t];
	}
}

void addedge(int x, int y, int z, double w) {
	e[++cnt] = (edge){x, y, head[x], z, 0, w}; head[x] = cnt;
	e[++cnt] = (edge){y, x, head[y], 0, 0, -w}; head[y] = cnt;
}

int t, n, m, x, y, z, flow_;
double w, cost;

int main() {
	for (scanf("%d", &t); t--; ) {
		int _ = 0; cnt = 1;
		memset(head, 0, sizeof head);
		flow_ = cost = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &x, &y);
			_ += x;
			if (x < y) addedge(1, i+1, y - x, 0);
			if (x > y) addedge(i+1, n+2, x - y, 0);
		}
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d%lf", &x, &y, &z, &w);
			if (z > 0) addedge(x, y, 1, 0);
			if (z-1 > 0) addedge(x, y, z-1, -log(1-w));
		}
		ek(1, n+2, flow_, cost);
		assert(flow_ == _);
		printf("%.2lf\n", 1 - exp(-cost));
	}
	return 0;
}