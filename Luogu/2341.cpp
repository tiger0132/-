#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, next;
} e[50004];

int deg[10004], cover[10004];
int head[10004], cnt;

int dfn[10004], low[10004], scc[10004], nds[10004], scnt, idx;
bool vis[10004];
stack<int> st;

void tarjan(int x) {
    dfn[x] = low[x] = ++idx; vis[x] = true;
    st.push(x);
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
			nds[scnt]++;
            scc[_] = scnt;
            vis[_] = false;
            if (_ == x) return;
        }
    }
}

void addedge(int x, int y) {
	e[++cnt] = (edge){x, y, head[x]}; head[x] = cnt;
}

int n, m, x, y, _, __;

int main() {
	for (scanf("%d%d", &n, &m); m--; ) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	m = cnt; cnt = 0;
	for (int i = 1; i <= m; i++) {
		int x = e[i].from, y = e[i].to;
		if (scc[x] != scc[y]) {
			addedge(scc[x], scc[y]);
			deg[scc[x]]++;
		}
	}
	for (int i = 1; i <= scnt; i++) {
		if (!deg[i]) {
			_++;
			__ = i;
		}
	}
	if (_ == 1) {
		printf("%d", nds[_]);
	} else puts("0");
	return 0;
}