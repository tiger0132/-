#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, next, capacity, flow, cost;
} e[100005];

int head[5003], cnt = 1;
int prev[5003];
int flow[5003];

void ek(int s, int t, int& rflow, long long& cost) {
	int dis[5003];
	int vis[5003];
	queue<int> bfs;
	while (1) {
		memset(prev, 0, sizeof prev);
		memset(flow, 0, sizeof flow);
		memset(dis, 0x3f, sizeof dis);
		memset(vis, 0, sizeof vis);
		bfs.push(s);
		flow[s] = 0x3f3f3f3f;
		dis[s] = 0;
		while (!bfs.empty()) {
			int pos = bfs.front(); bfs.pop();
			vis[pos] = 0;
			for (int i = head[pos]; i; i = e[i].next) {
				int nx = e[i].to;
				if (e[i].flow < e[i].capacity && dis[nx] > dis[pos] + e[i].cost) {
					dis[nx] = dis[pos] + e[i].cost;
					flow[nx] = min(flow[pos], e[i].capacity - e[i].flow);
					prev[nx] = i;
					if (!vis[nx]) {
						bfs.push(nx);
						vis[nx] = 1;
					}
				}
			}
		}
		if (!prev[t]) break;
		for (int i = prev[t]; i; i = prev[e[i].from]) {
			e[i].flow += flow[t];
			e[i^1].flow -= flow[t];
		}
		rflow += flow[t];
		cost += dis[t] * flow[t];
	}
}

void addedge(int x, int y, int z, int w) {
	e[++cnt] = (edge){x, y, head[x], z, 0, w}; head[x] = cnt;
	e[++cnt] = (edge){y, x, head[y], 0, 0, -w}; head[y] = cnt;
}

int n, m, s, t, x, y, z, w, rflow;
long long cost;

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	while (m--) {
		scanf("%d%d%d%d", &x, &y, &z, &w);
		addedge(x, y, z, w);
	}
	ek(s, t, rflow, cost);
	printf("%d %lld", rflow, cost);
	return 0;
}