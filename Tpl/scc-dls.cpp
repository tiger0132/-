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

int main() {

	for (int i = 0; i < n; i++) {
		if (!dfn[i]) dfs(i);
	}
}sort