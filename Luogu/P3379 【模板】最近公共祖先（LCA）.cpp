#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next;
} e[500005];

struct query {
	int to, ans, next;
} q[500005];

int n, m, r, u, v, ec = 1;
int heade[500005];
int headq[500005];
int lca[500005];
int par[500005];
int vis[500005];

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y;
}

void adde(int x, int y) {
	e[++ec] = (edge){y, heade[x]}; heade[x] = ec;
	e[++ec] = (edge){x, heade[y]}; heade[y] = ec;
}

void addq(int x, int y) {
	q[++ec] = (query){y, 0, headq[x]}; headq[x] = ec;
	q[++ec] = (query){x, 0, headq[y]}; headq[y] = ec;
}

void dfs(int x) {
	vis[x] = 1;
	int nx;
	for (int i = heade[x]; i; i = e[i].next) {
		nx = e[i].to;
		if (vis[nx]) continue; // 父节点
		dfs(nx);
		merge(x, nx);
		lca[find(nx)] = x;
	}
	for (int i = headq[x]; i; i = q[i].next) {
		nx = q[i].to;
		if (vis[nx]) q[i^1].ans = q[i].ans = find(nx);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		adde(u, v);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		addq(u, v);
	}
	dfs(r);
	for (int i = 1; i <= m; i++) {
		printf("%d\n", q[i<<1].ans);
	}
}