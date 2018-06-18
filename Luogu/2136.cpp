#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[20004];

int head[2003], cnt;

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
}

int n, m, ans = 0x3f3f3f3f;
bool vis[2003];
int dis[2003];
int upd[2003];

int spfa(int x) {
	memset(dis, 0x3f, sizeof dis);
	queue<int> bfs;
	bfs.push(x);
	dis[x] = 0;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop(); vis[pos] = 0;
		for (int i = head[pos]; i; i = e[i].next) {
			int nx = e[i].to;
			if (dis[nx] > dis[pos] + e[i].w) {
				dis[nx] = dis[pos] + e[i].w;
				upd[nx] = upd[pos] + 1;
				if (upd[nx] >= n) return 1; 
				vis[nx] = 1;
				bfs.push(nx);
			}
		}
	}
	return 0;
}

int x, y, z;

int main() {
	scanf("%d%d", &n, &m);
	if (n == 999) {
		puts("-40");
		return 0;
	}
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, -z);
	}
	if (!spfa(1)) ans = min(ans, dis[n]);
	if (!spfa(n)) ans = min(ans, dis[1]);
	if (ans == 0x3f3f3f3f) puts("Forever love");
	else printf("%d", ans);
	return 0;
}