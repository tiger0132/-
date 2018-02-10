#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, s, dep[500005];
vector<int> tree[500005]; 
int table[500005][19];
int par[500005];

inline void bfs(int root) {
    queue<int> bfs;
    bfs.push(root);
    dep[root] = 1;
    par[root] = root;
    while (!bfs.empty()) {
        int index = bfs.front();
        bfs.pop();
        for (int i = 0; i < tree[index].size(); i++) {
            if (!dep[tree[index][i]]) {
                dep[tree[index][i]] = dep[index] + 1;
                par[tree[index][i]] = index;
                bfs.push(tree[index][i]);
            }
        }
    }
}

inline void pre() {
    for (int i = 1; i <= n; i++) {
        table[i][0] = par[i];
    }
    for (int j = 1; j < 19; j++) {
        for (int i = 1; i <= n; i++) {
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
} 

inline int lca(int x, int y) {
    int dx = dep[x];
    int dy = dep[y];
    if (dx > dy) {
        swap(x, y);
        swap(dx, dy);
    }
    int sub = dy - dx;
    for (int i = 0; (1 << i) <= sub; i++) {
        if ((1 << i) & sub) {
            y = table[y][i];
        }
    }
    for (int i = 18; i >= 0; i--) {
        if (table[x][i] != table[y][i]) {
            x = table[x][i];
            y = table[y][i];
        }
    }
    return x == y ? x : par[x];
} 

inline int read() {
    int ret = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
    	ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
    	ret = ret * 10 + ch - 48;
        ch = getchar(); 
    }
    return ret;
}

int main() {
    n = read();
    m = read();
    s = read();
    for (int i = 1; i < n; i++) {
        u = read();
        v = read();
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    bfs(s); 
    pre();
    while (m--) {
        u = read();
        v = read();
        printf("%d\n", lca(u, v));
    }
}
