#include <bits/stdc++.h>
using namespace std;

const int N = 10004, M = 100005;

struct edge {
	int to, next;
} e[M];

int head[N << 1], vis[N], dfn[N], low[N], scc[N], dp[N], dgr[N];
int edge_cnt, dfn_index, scc_count;
stack<int> st;

void tarjan(int x) {
	dfn[x] = low[x] = ++dfn_index;
	vis[x] = 1; st.push(x);
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dfn[nx]) {
			tarjan(nx);
			low[x] = min(low[x], low[nx]);
		} else if (vis[nx] && dfn[nx] < low[x]) {
			low[x] = min(low[x], dfn[nx]);
		}
	}
	if (dfn[x] == low[x]) {
		scc_count++;
		while (!st.empty()) {
			int _ = st.top(); st.pop();
			scc[_] = scc_count;
			vis[_] = 0;
			if (_ == x) break;
		}
	}
}

void addEdge(int x, int y) {
	e[++edge_cnt] = (edge){y, head[x]}; head[x] = edge_cnt;
	dgr[y]++;
}

int n, m, u, v, ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		addEdge(u, v);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
	memset(head, 0, sizeof head);
	memset(e, 0, sizeof e);
	edge_cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (scc[u[i]] == scc[v[i]]) continue;
		addEdge(scc[u[i]], scc[v[i]]);
	}
	for (int i = 1; i <= n; i++) {

	}
	printf("%d", ans);
	return 0;
}