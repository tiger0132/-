#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[200005];

int t, r, p, s, u, v, w;
int head[25004], cnt;
bool vis[25004];
deque<int> bfs;
int dep[25004];

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
}

void spfa() {
	memset(dep, 0x3f, sizeof dep);
	bfs.push_front(s);
	dep[s] = 0;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop_front();
		vis[pos] = 1;
		for (int i = head[pos]; i; i = e[i].next) {
			int nx = e[i].to;
			if (dep[nx] > dep[pos] + e[i].w) {
				dep[nx] = dep[pos] + e[i].w;
				if (!vis[nx]) {
					vis[nx] = 1;
					if (!bfs.empty() && dep[nx] < dep[bfs.front()]) bfs.push_front(nx);
					else bfs.push_back(nx); 
				}
			}
		}
		vis[pos] = 0;
	}
	for (int i = 1; i <= t; i++) {
		if (dep[i] == 0x3f3f3f3f) puts("NO PATH");
		else printf("%d\n", dep[i]);
	}
}

int main() {
	scanf("%d%d%d%d", &t, &r, &p, &s);
	while (r--) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	while (p--) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
	}
	spfa();
	return 0;
}