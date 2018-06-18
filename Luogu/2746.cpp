#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to, next;
} e[50004];

int head[102], cnt;

int dfn[102], low[102], scc[102], scnt, idx;
int in[102], out[102];
bool vis[102];
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
            scc[_] = scnt;
            vis[_] = false;
			if (_ == x) return;
        }
    }
}

void addedge(int x, int y) {
    e[++cnt] = (edge){x, y, head[x]}; head[x] = cnt;
}

int n, m, x, _, __;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        while (scanf("%d", &x), x) {
			addedge(i, x);
		}
    }
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}
	m = cnt; cnt = 0;
	for (int i = 1; i <= m; i++) {
		int x = scc[e[i].from];
		int y = scc[e[i].to];
		if (x != y) {
			addedge(x, y);
			out[x]++; in[y]++;
		}
	}
	for (int i = 1; i <= scnt; i++) {
		_ += !in[i];
		__ += !out[i];
	}
	printf("%d\n%d", _, (scnt > 1) * max(_, __));
	return 0;
}