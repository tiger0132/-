#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, next, capacity, flow, cost;
} e[100005];

int head[5003], cnt = 1;
int pre[5003];
int flow[5003];

void ek(int s, int t, int& rflow, long long& cost) {
	int dis[5003];
	int vis[5003];
	queue<int> bfs;
	while (1) {
		memset(pre, 0, sizeof pre);
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
					pre[nx] = i;
					if (!vis[nx]) {
						bfs.push(nx);
						vis[nx] = 1;
					}
				}
			}
		}
		if (!pre[t]) break;
		for (int i = pre[t]; i; i = pre[e[i].from]) {
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

int n, m, x, y, z, rflow;
long long cost;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(e, 0, sizeof e); cnt = 1;
		memset(head, 0, sizeof head);
		rflow = 0; cost = 0;
		for (int i = 2; i < n; i++) {
			addedge(i, i+n, 1, 0);
		}
		addedge(1, n+1, 2, 0);
		addedge(n, n<<1, 2, 0);
		while (m--) {
			scanf("%d%d%d", &x, &y, &z);
			addedge(x+n, y, 1, z);
		}
		ek(1, n<<1, rflow, cost);
		assert(rflow == 2);
		printf("%lld\n", cost);
	}
	return 0;
}