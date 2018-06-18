#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, w;
} e[200005];

int dep1[100005], dep2[100005];
int l1[100005], l2[100005];
int head[100005], cnt = 1;
int root;

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z}; head[y] = cnt;
}

void dfs(int x, int par) {
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (nx == par) continue;
		dfs(nx, x);
		if (dep1[nx] + e[i].w > dep1[x]) {
			dep2[x] = dep1[x];
			dep1[x] = dep1[nx] + e[i].w;
			l2[x] = l1[x];
			l1[x] = i;
		} else if (dep1[nx] + e[i].w > dep2[x]) {
			dep2[x] = dep1[nx] + e[i].w;
			l2[x] = i;
		}
	}
	if (dep1[x] + dep2[x] > dep1[root] + dep2[root]) root = x;
}

int n, k, ans, x, y;

int main() {
 	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		addedge(x, y, 1);
	}
	root = 0; dfs(1, -1);
	ans = (n-1) * 2 - dep1[root] - dep2[root] + 1;
	if (k == 1) {
		printf("%d", ans);
		return 0;
	}
	for (int i = l1[root]; i; i = l1[e[i].to]) e[i].w = e[i^1].w = -1;
	for (int i = l2[root]; i; i = l1[e[i].to]) e[i].w = e[i^1].w = -1;
	memset(l1, 0, sizeof l1); memset(l2, 0, sizeof l2);
	memset(dep1, 0, sizeof dep1); memset(dep2, 0, sizeof dep2);
	root = 0;
	dfs(1, -1);
	ans -= dep1[root] + dep2[root] - 1;
	printf("%d", ans);
	return 0;
}