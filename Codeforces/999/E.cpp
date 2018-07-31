#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, next;
} e[10004];

int dfn[10004], low[10004], vis[10004], scc[10004], wgt[10004], idx, scnt;
int head[10004], cnt;
int deg[10004];
stack<int> st;

void tarjan(int x) {
	dfn[x] = low[x] = ++idx;
	vis[x] = 1; st.push(x);
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dfn[nx]) {
			tarjan(nx);
			low[x] = min(low[x], low[nx]);
		} else if (vis[nx]) {
			low[x] = min(low[x], dfn[nx]);
		}
	}
	if (dfn[x] == low[x]) {
		scnt++;
		while (!st.empty()) {
			int _ = st.top(); st.pop();
			scc[_] = scnt;
			vis[_] = 0;
			wgt[_]++;
			if (_ == x) break;
		}
	}
}

void addedge(int x, int y) {
	e[++cnt] = (edge){x, y, head[x]}; head[x] = cnt;
}

int n, m, s, x, y, ans;

int main() {
	scanf("%d%d%d", &n, &m, &s);
	while (m--) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= cnt; i++) {
		if (scc[e[i].from] != scc[e[i].to]) deg[scc[e[i].to]]++;
	}
	deg[scc[s]] = 1;
	for (int i = 1; i <= scnt; i++) {
		ans += !deg[i];
	}
	printf("%d", ans);
	return 0;
}