#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, next, w;
} e[20004];

struct edge2 {
	int from, to, w;
	bool operator<(const edge2& rhs) const {
		return w > rhs.w;
	}
} e2[100005];

int head[10004], dep[10004], cnt = 1;
int table[10004][15], n, m;
int w[10004][15];
int par[10004];

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

int merge(int x, int y) {
	if ((x = find(x)) == (y = find(y))) return 0;
	par[x] = y; return 1;
}

void bfs_(int x) {
    stack<int> bfs;
    bfs.push(x);
    dep[x] = 1;
    while (!bfs.empty()) {
        int pos = bfs.top(); bfs.pop();
        for (int i = head[pos]; i; i = e[i].next) {
            int nx = e[i].to;
            if (!dep[nx]) {
                dep[nx] = dep[pos] + 1;
                table[nx][0] = pos;
				w[nx][0] = e[i].w;
                bfs.push(nx);
            }
        }
    }
}

void prework() {
	for (int i = 1; i <= n; i++) {
		if (!dep[i]) bfs_(i);
	}
    for (int j = 1; j < 15; j++) {
        for (int i = 1; i <= n; i++) {
            table[i][j] = table[table[i][j-1]][j-1];
			w[i][j] = min(w[i][j-1], w[table[i][j-1]][j-1]);
        }
    }
}

int lca(int x, int y) {
    int dx = dep[x], dy = dep[y], ret = 0x3f3f3f3f;
    if (dx > dy) swap(x, y), swap(dx, dy);
    int sub = dy - dx;
    for (int i = 0; (1 << i) <= sub; i++) {
        if ((1 << i) & sub) {
			ret = min(ret, w[y][i]);
            y = table[y][i];
        }
    }
	if (x == y) return ret;
    for (int i = 14; i >= 0; i--) {
        if (table[x][i] != table[y][i]) {
			ret = min(ret, min(w[x][i], w[y][i]));
            x = table[x][i];
            y = table[y][i];
        }
    }
    return min(ret, min(w[x][0], w[y][0]));
}

void addedge(int x, int y, int z) {
    e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
    e[++cnt] = (edge){x, head[y], z}; head[y] = cnt;
}

void kruskal() {
	int cur = 0;
	for (int i = 1; i <= m; i++) {
		if (merge(e2[i].from, e2[i].to)) {
			cur++;
			addedge(e2[i].from, e2[i].to, e2[i].w);
		}
		if (cur == n-1) return;
	}
}

int q, x, y;

int main() {
	// freopen("ber.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e2[i].from, &e2[i].to, &e2[i].w);
	}
	sort(e2+1, e2+m);
	kruskal();
	prework();
	for (scanf("%d", &q); q--; ) {
		scanf("%d%d", &x, &y);
		printf("%d\n", find(x) == find(y) ? lca(x, y) : -1);
	}
	return 0;
}