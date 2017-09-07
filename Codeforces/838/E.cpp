#include <bits/stdc++.h>
using namespace std;

int par[200005], w1[200005], w2[200005];
int n, a[400005], b[400005], c[400005];
int dep[200005], table[200005][19];
int w[200005][19];

vector<tuple<int, int, int>> graph;
vector<int> tree[200005];

inline void dfs(int index) {
	for (int i : tree[index]) {
		if (!dep[i]) {
			dep[i] = dep[index] + 1;
			dfs(i);
		}
	}
}

inline void pre() {
	for (int i = 1; i <= n; i++) {
		table[i][0] = par[i];
		w[i][0] = w1[i];
	}
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= n; i++) {
			table[i][j] = table[table[i][j - 1]][j - 1];
			w[i][j] = w[i][j - 1] + w[table[i][j - 1]][j - 1];
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

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= (n - 1) * 2; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (i < n) {
			par[a] = b;
			w1[a] = c;
			
		} else {
			w2[a] = c;
		}
	}
	dfs(1);
	
}
