#include <bits/stdc++.h>
using namespace std;

const int N = 1003, M = 1000006;

struct edge {
	int to, next;
} e[M];

int head[N], match[N];
int edge_cnt;
bool vis[N];

bool dfs(int x) {
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!vis[nx]) {
			vis[nx] = 1;
			if (!match[nx] || dfs(match[nx])) {
				match[nx] = x;
				return 1;
			}
		}
	}
	return 0;
}

void addEdge(int x, int y) {
	e[++edge_cnt] = (edge){y, head[x]}; head[x] = edge_cnt;
}

int n, m, E, u, v, ans;

int main() {
	scanf("%d%d%d", &n, &m, &E);
	for (int i = 1; i <= E; i++) {
		scanf("%d%d", &u, &v);
		if (u <= n && v <= m) addEdge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof vis);
		if (dfs(i)) ans++;
	}
	printf("%d", ans);
	return 0;
}