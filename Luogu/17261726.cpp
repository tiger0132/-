#include <bits/stdc++.h>
using namespace std;

const int N = 5003, M = 100005;

struct Edge {
	int to, next;
} e[M];

int head[N];

int dfn[N], low[N], vis[N], tmp[N], ans[N], ign[N];
int dfn_index, scc_count, ans_len, edge_count;
stack<int> st;
int n, m;

void tarjan(int cur) {
	dfn[cur] = low[cur] = ++dfn_index;
	vis[cur] = 1; st.push(cur);
	for (int i = head[cur]; i; i = e[i].next) {
		int nxt = e[i].to;
		if (!dfn[nxt]) {
			tarjan(nxt);
			low[cur] = min(low[cur], low[nxt]);
		} else if (vis[nxt] && dfn[nxt] < low[cur]) {
			low[cur] = min(low[cur], dfn[nxt]);
		}
	}
	if (low[cur] == dfn[cur]) {
		memset(tmp, 0, sizeof(tmp));
		scc_count++;
		int _ = 0;
		while (!st.empty()) {
			int x = st.top(); st.pop();
			tmp[++_] = x;
			vis[x] = 0;
			ign[x] = 1;
			if (x == cur) break;
		}
		sort(tmp + 1, tmp + _ + 1);
		if (_ > ans_len || (_ == ans_len && tmp[1] < ans[1])) {
			ans_len = _;
			memcpy(ans, tmp, sizeof ans);
		}
	}
}

void addEdge(int u, int v, int _) {
	e[++edge_count] = (Edge){v, head[u]};
	head[u] = edge_count;
	if (_ == 2) {
		e[++edge_count] = (Edge){u, head[v]};
		head[v] = edge_count;
	}
}

int u, v, w;

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &u, &v, &w);
		addEdge(u, v, w);
	}
	for (int i = 1; i <= n; i++) {
		if (!ign[i]) {
			tarjan(i);
		}
	}
	printf("%d\n", ans_len);
	for (int i = 1; i <= ans_len; i++) {
		printf("%d ", ans[i]);
	}
	// while (1);
}