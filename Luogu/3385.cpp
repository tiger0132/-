#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, next, w;
} e[1000006];

int op, n, m, u, v, w;
int head[20004], cnt;
bool vis[20004], f;
int dis[20004];
int upd[20004];

void addedge(int x, int y, int z) {
    e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
}

void spfa(int x) {
	vis[x] = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (dis[nx] > dis[x] + e[i].w) {
			dis[nx] = dis[x] + e[i].w;
			upd[nx] = upd[x] + 1;
			if (upd[nx] > n) {
				f = 1;
				return;
			}
			if (vis[nx]) continue;
			vis[nx] = 1;
			spfa(nx);
		}
	}
}

int main() {
    for (scanf("%d%d", &n, &m); m--; ) {
        scanf("%d%d%d", &op, &u, &v); u++; v++;
        if (op == 3) {
            addedge(u, v, 0);
            addedge(v, u, 0);
            continue;
        }
        scanf("%d", &w); w++;
        if (op == 1) {
            addedge(u, v, -w);
        } else {
            addedge(v, u, w);
        }
    }
    n++;
    for (int i = 1; i <= n; i++) {
        addedge(n+1, i, 0);
    }
	memset(dis, 127, sizeof dis);
	dis[n+1] = 0;
	spfa(n+1);
    puts(f ? "No" : "Yes");
    return 0;
}