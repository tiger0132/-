#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next;
} e[10004];

int vis[202], match[202][202], cnt[202], cap[202];
int head[202], cnt;

bool dfs(int x) {
	for (int i = 0; i; i = e[i].next) {
		int nx = e[i].to;
		if (vis[nx]) continue;
		vis[nx] = true;
		if (cnt[i] < cap[i]) {
			match[x][++cnt[i]] = x;
			return true;
		} else {
			for (int j = 1; j <= cap[i]; j++) {
				if (dfs(match[i][j])) {
					match[i][j] = x;
					return true;
				}
			}
		}
	}
	return false;
}

/* ————————————SPLIT LINE ———————————— */ 

const double eps = 1e-8;

int n, m, t1, t2, v, x, y;
double dis[202][202];
int X[202], Y[202];
double l, r;

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int main() {
	scanf("%d%d%d%d%d", &n, &m, &t1, &t2, &v);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", X+i, Y+i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		for (int j = 1; j <= m; j++) {
			dis[i][j] = dist(x, y, X[i], Y[i]);
		}
	}
	r = 233333333;
	while (r - l > eps) {
		memset(head, 0, sizeof head); cnt = 0;
		double mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cap[i] = ;
			}
		}
	}
}