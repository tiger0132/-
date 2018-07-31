// Network Flow Template by tiger0132

#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, capacity, flow;
} e[500005];

int level[4003], head[4003], cnt = 1;

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

const double eps = 1e-7;

struct xy {
	double x, y;
} enemy[102], missle[102];

double l, r, st, v, mid;
int n, m, t1, t2, x, y;
double dis[102][102];

double dist(double X1, double Y1, double X2, double Y2) {
	return sqrt((X1-X2) * (X1-X2) + (Y1-Y2) * (Y1-Y2));
}

int main() {
	scanf("%d%d%d%d%lf", &n, &m, &t1, &t2, &v);
	for (int i = 1; i <= m; i++) {
		scanf("%lf%lf", &enemy[i].x, &enemy[i].y);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &missle[i].x, &missle[i].y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] = dist(missle[i].x, missle[i].y, enemy[j].x, enemy[j].y);
		}
	}
	r = 500000;
	while (r - l > eps) {
		memset(head, 0, sizeof head); cnt = 1;
		mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				addedge(4001, j*60 + i, 1);
			}
		}
		for (int i = 1; i <= n; i++) {
			// st = t1 / 60.;
			for (int j = 0; j < m; j++) {
				st = t1 * (j+1) / 60. + t2 * j;
				for (int k = 1; k <= m; k++) {
					if (st + dis[i][k] / v < mid) {
						addedge(j*60 + i, 3900 + k, 1);
					}
				}
				// st += t1 / 60. + t2;
			}
		}
		for (int i = 1; i <= m; i++) {
			addedge(3900 + i, 4000, 1);
		}
		if (dinic(4001, 4000) == m) r = mid;
		else l = mid;
	}
	printf("%.6f\n", mid);
	return 0;
}