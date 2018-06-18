#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to, next;
} e[20004];

int deg[3003], srcv[3003], val[3003], controlled;
int head[3003], cnt, ans, m;
bool vis[3003];

void addedge(int x, int y) {
    e[++cnt] = (edge){x, y, head[x]}; head[x] = cnt;
}

int idx, scnt, dfn[3003], low[3003], scc[3003], id[3003];
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
		val[++scnt] = srcv[x];
		id[scnt] = x;
		// printf("scc #%d:\n", scnt);
		while (!st.empty()) {
			int _ = st.top(); st.pop();
			// printf("%d\n", _);
			scc[_] = scnt;
			vis[_] = false;
			id[scnt] = min(id[scnt], _);
			val[scnt] = min(val[scnt], srcv[_]);
			if (_ == x) return;
		}
	}
}

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    controlled++;
    for (int i = head[x]; i; i = e[i].next) {
        dfs(e[i].to);
    }
}

int n, k, x, y;

int main() {
    memset(srcv, 0x3f, sizeof srcv);
    scanf("%d%d", &n, &k);
    while (k--) {
        scanf("%d%d", &x, &y);
        srcv[x] = min(srcv[x], y);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d%d", &x, &y);
        addedge(x, y);
    }
	
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) tarjan(i);
	}

	n = scnt; m = cnt;
	memset(head, 0, sizeof head); cnt = 0;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= m; i++) {
		if (scc[e[i].from] != scc[e[i].to]) {
			deg[scc[e[i].to]]++;
			addedge(scc[e[i].from], scc[e[i].to]);
		}
	}
	
    for (int i = 1; i <= n; i++) {
        if (!deg[i]) {
            if (val[i] == 0x3f3f3f3f) {
                printf("NO\n%d", id[i]);
                return 0;
            }
            ans += val[i];
            dfs(i);
        }
    }
    assert(controlled == n);
    printf("YES\n%d", ans);
    return 0;
}