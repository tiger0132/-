#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[1000006];

int op, n, m, u, v, w;
int head[200005], cnt;
bool flag[200005];
bool vis[200005];
int dis[200005];
int upd[200005];

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
}

int spfa(int x) {
	vis[x] = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (dis[nx] > dis[x] + e[i].w) {
			dis[nx] = dis[x] + e[i].w;
			upd[nx] = upd[x] + 1;
			if (upd[nx] > n) return 0;
			if (!vis[nx]) {
				vis[nx] = 1;
				if (!spfa(nx)) return 0;
			}
		}
	}
	return 1;
}

int main() {
	for (scanf("%d%d", &n, &m); m--; ) {
		scanf("%d%d%d", &op, &u, &v);
		if (op == 3) {
			addedge(u, v, 0);
			addedge(v, u, 0);
			continue;
		}
		scanf("%d", &w);
		if (op == 1) {
			addedge(u, v, -w);
		} else {
			addedge(v, u, w);
		}
	}
	for (int i = 1; i <= n; i++) {
		addedge(0, i, 0);
	}
	memset(dis, 0x3f, sizeof dis);
	dis[0] = 0;
	puts(spfa(0) ? "Yes" : "No");
	return 0;
}