#include <bits/stdc++.h>
using namespace std;

vector<int> e[1000001];
int n, m, x, a, b, ind;
int low[1000001];
int dfn[1000001];
int ins[1000001];
int st[1000001];

void dfs(int u) {
	dfn[u] = low[u] = ++ind; // index
	ins[u] = 1; // instack(没形成强连通分量的栈)
	st[++top] = u;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			dfs(v);
			low[u] = min(low[u], dfs(low[v]));
		} else if (ins[v]) { // 不是强连通分量
			low[u] = min(low[u], dfn[v]); // 可以换成low[v]
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		while (1) {
			bel[st[top]] = cnt; // belong
			ins[st[top]] = 0;
			if (st[top--] == u) break;
		}
	}
}

# gaolin

int main() {
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) {
			dfs(i);
		}
	}
	
}