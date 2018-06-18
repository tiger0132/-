#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	scanf("%d%d", &a, &b);
	printf("%d", a+b);
}

#if 0

Luogu AC BZOJ(Offline) RE?

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

bool cut[100005];

void tarjan(int cur) {
	dfn[cur] = low[cur] = ++dfn_index; size[cur] = 1;
	int conn_cnt = 0, size_cnt = 0;
	for (int i = head[cur]; i; i = e[i].next) {
		int nxt = e[i].to;
		if (!dfn[nxt]) {
			tarjan(nxt);
			size[cur] += size[nxt];
			low[cur] = min(low[cur], low[nxt]);
			if (low[nxt] >= dfn[cur]) {
				conn_cnt++;
				ans[cur] += (ll)(n - size[nxt]) * size[nxt];
				size_cnt += size[nxt];
				if (conn_cnt > 1 || cur > 1) cut[cur] = 1;
			}
		} else {
			low[cur] = min(low[cur], dfn[nxt]);
		}
	}
	if (cut[cur]) ans[cur] += (ll)(size_cnt + 1) * (n - size_cnt - 1) + n - 1;
	else ans[cur] = (n-1)<<1;
}

void addEdge(int u, int v) {
	e[++edge_count] = (edge){v, head[u]};
	head[u] = edge_count;
}

int u, v;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &u, &v);
		addEdge(u, v);
		addEdge(v, u);
	}
	tarjan(1);
	for (int i = 1; i <= n; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}

#endif