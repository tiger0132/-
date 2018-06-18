#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int to, next;
} e[1000006];

int head[100005];

int n, m, dfn[100005], low[100005], size[100005];
int edge_count, dfn_index;
ll ans[100005];

// bool cut[100005];

int tarjan(int x) { // PERFECT! NO CUT ARRAY HAHAHA
	dfn[x] = low[x] = ++dfn_index;
	size[x] = 1;
	int sc = 0;
	for(int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dfn[nx]) {
			tarjan(nx);
			size[x] += size[nx];
			low[x] = min(low[x], low[nx]);
			if (dfn[x] <= low[nx]) {
				ans[x] += (ll)sc * size[nx];
				sc += size[nx];
			}
		} else low[x] = min(low[x], dfn[nx]);
	}
	ans[x] += (ll)sc * (n - sc - 1);
}

void addEdge(int u, int v) {
	e[++edge_count] = (edge){v, head[u]}; head[u] = edge_count;
}

int u, v;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		assert(u != v);
		addEdge(u, v);
		addEdge(v, u);
	}
	tarjan(1);
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", (ans[i] + n - 1) << 1);
	}
	return 0;
}