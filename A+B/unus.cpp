#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[400005];

int head[200005], cnt, n, m;
bool flag[200005];
bool vis[200005];
int dis[200005];
int upd[200005];

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
}

int spfa(int x) {
    queue<int> bfs;
    bfs.push(x);
    while (!bfs.empty()) {
        int pos = bfs.front(); bfs.pop(); vis[pos] = 0;
        for (int i = head[pos]; i; i = e[i].next) {
            int nx = e[i].to;
            if (dis[nx] < dis[pos] + e[i].w) {
                dis[nx] = dis[pos] + e[i].w;
                if (upd[nx]++ >= n) return 1; 
                vis[nx] = 1;
                bfs.push(nx);
            }
        }
    }
    return 0;
}

long long ans;
int op, x, y;

int main() {
	for (scanf("%d%d", &n, &m); m--; ) {
		scanf("%d%d%d", &op, &x, &y);
		if (!(op&1) && x == y) {
			puts("-1");
			return 0;
		}
		switch (op) {
			case 1: addedge(x, y, 0); addedge(y, x, 0); break;
			case 2: addedge(x, y, 1); break;
			case 3: addedge(y, x, 0); break;
			case 4: addedge(y, x, 1); break;
			default: addedge(x, y, 0);
		}
	}
	for (int i = n; i; i--) addedge(0, i, 1);
	dis[0] = 0;
	if (spfa(0)) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		ans += dis[i];
	}
	printf("%lld", ans);
	return 0;
}