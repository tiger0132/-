#include <bits/stdc++.h>
using namespace std;

const int N = 100005, M = 200005;

struct Edge {
    int to, next;
} e[M];

int head[N];

int cut_count, edge_count, dfn_index;
int n, m, dfn[N], low[N], par[N];

bool cut[N];

void tarjan(int cur) {
    dfn[cur] = low[cur] = ++dfn_index;
    int cnt = 0;
    for (int i = head[cur]; i; i = e[i].next) {
        int nxt = e[i].to;
        if (nxt == par[cur]) continue;
        if (!dfn[nxt]) {
            cnt++;
            par[nxt] = cur;
            tarjan(nxt);
            low[cur] = min(low[cur], low[nxt]);
            if (par[cur] && low[nxt] >= dfn[cur]) {
                cut_count += !cut[cur];
                cut[cur] = 1;
            }
        } else {
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }
    if (!par[cur] && cnt >= 2) {
        cut_count += !cut[cur];
        cut[cur] = 1;
    } 
}

void addEdge(int u, int v) {
    e[++edge_count] = (Edge){v, head[u]};
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
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    printf("%d\n", cut_count);
    for (int i = 1; i <= n; i++) {
        if (cut[i]) {
            printf("%d ", i);
        }
    }
}