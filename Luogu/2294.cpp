#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[10004];

int dis[1003], upd[1003];
int head[1003], cnt, n;
bool vis[1003];

bool spfa() {
	memset(dis, 0x3f, sizeof dis);
	queue<int> bfs;
	bfs.push(0);
	dis[0] = 0;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		if (++upd[pos] >= n) return false;
		for (int i = head[pos]; i; i = e[i].next) {
			int nx = e[i].to;
			if (dis[nx] > dis[pos] + e[i].w) {
				dis[nx] = dis[pos] + e[i].w;
				if (!vis[nx]) {
					vis[nx] = true;
					bfs.push(nx);
				}
			}
		}
		vis[pos] = false;
	}
	return true;
}

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
}

int t, m, x, y, z;

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(head, 0, sizeof head); cnt = 0;
		memset(vis, 0, sizeof vis);
		memset(upd, 0, sizeof upd);
		memset(e, 0, sizeof e);
		for (scanf("%d%d", &n, &m); m--; ) {
			scanf("%d%d%d", &x, &y, &z); x++; y++;
			addedge(x-1, y, -z);
			addedge(y, x-1, z);
		}
		for (int i = 1; i <= n+1; i++) {
			addedge(0, i, 0);
		}
		puts(spfa() ? "true" : "false");
	}
	return 0;
}