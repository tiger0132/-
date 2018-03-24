#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 1000006;

struct edge {
	int to, next;
} e[M];

int head[N << 1], wgt[N], vis[N], dfn[N], low[N], scc[N], dp[N], g[N], _vis[N];
int edge_cnt, dfn_index, scc_count, mod;
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
			wgt[scc_count]++;
			if (_ == x) break;
		}
	}
}

void addEdge(int x, int y) {
	e[++edge_cnt] = (edge){y, head[x]}; head[x] = edge_cnt;
}

void dfs(int x) {
	memset(_vis, 0, sizeof _vis);
	if (dp[x]) return;
	dp[x] = wgt[x];
	g[x] = 1;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (_vis[nx]) continue;
		_vis[nx] = 1;
		if (!dp[nx]) dfs(nx);
		if (dp[x] == dp[nx] + wgt[x]) {
			g[x] = (g[x] + g[nx]) % mod;
		} else if (dp[x] < dp[nx] + wgt[x]) {
			dp[x] = dp[nx] + wgt[x];
			g[x] = g[nx];
		}
	}
	// if (dp[x]) return;
	// dp[x] = wgt[x];
	// int ret = 0;
	// for (int i = head[x]; i; i = e[i].next){
	// 	if (!dp[e[i].to]) dfs(e[i].to);
	// 	ret = max(ret, dp[e[i].to]);
	// }
	// dp[x] += ret;
}

int n, m, u[M], v[M], ans, c;

int main() {
	scanf("%d%d%d", &n, &m, &mod);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", u+i, v+i);
		addEdge(u[i], v[i]);
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
	for (int i = 1; i <= scc_count; i++) {
		if (!dp[i]) {
			dfs(i);
			if (dp[i] > ans) {
				ans = dp[i];
				c = g[i];
			} else if (dp[i] == ans) {
				c = (c + g[i]) % mod;
			}
		}
	}
	printf("%d\n%d", ans, c);
	return 0;
}