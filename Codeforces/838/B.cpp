#include <bits/stdc++.h>
using namespace std;

int n, q, a[400005], b[400005], c[400005];
int par[200005], w1[200005], w2[200005];
int dep[200005], table[200005][19];
int w[200005][19], x, y, z;
bool vis[200005];

vector<tuple<int, int, int>> graph;
vector<int> tree[200005];

inline void dfs(int index) {
	vis[index] = true;
	for (int i : tree[index]) {
		if (!vis[i]) {
			par[i] = index;
			dep[i] = dep[index] + 1;
//			cout << index << " -> " << i << endl;
			dfs(i);
		}
	}
}

inline void pre() {
	for (int i = 1; i <= n; i++) {
		table[i][0] = par[i];
//		cout << par[i] << " ";
		w[i][0] = w1[i];
	}
	for (int j = 1; j < 19; j++) {
		for (int i = 1; i <= n; i++) {
			table[i][j] = table[table[i][j - 1]][j - 1];
			w[i][j] = w[i][j - 1] + w[table[i][j - 1]][j - 1];
		}
	}
	cout << endl << endl;
	cout << "w:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 19; j++) {
			cout << w[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "table:" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 19; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
 
inline int lca(int x, int y) {
	int dx = dep[x];
	int dy = dep[y];
	int len = 0;
	if (dx > dy) {
		swap(x, y);
		swap(dx, dy);
	}
	int sub = dy - dx;
	for (int i = 0; (1 << i) <= sub; i++) {
		if ((1 << i) & sub) {
//			cout << "y = " << y << ", w = " << w[y][i] << endl;
			y = table[y][i];
			len += w[y][i];
		}
	}
	for (int i = 18; i >= 0; i--) {
		if (table[x][i] != table[y][i]) {
//			cout << "x = " << x << ", y = " << y << endl;
			x = table[x][i];
			y = table[y][i];
			len += w[x][i] + w[y][i];
		}
	}
	if (x != y) {
		len += w[x][0] + w[y][0];
	}
	return len;
} 

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= (n - 1) * 2; i++) {
		cin >> a[i] >> b[i] >> c[i];
		if (i < n) {
//			cout << "! " << a[i] << " " << b[i] << endl;
			tree[b[i]].push_back(a[i]);
			tree[a[i]].push_back(b[i]);
		} else {
			w2[a[i]] = c[i];
		}
	}
	cout << endl << endl;
	par[1] = 0;
	dfs(1);
	for (int i = 1; i < n; i++) {
		if (a[i] == par[b[i]]) {
			w1[b[i]] = c[i];
		} else {
			w1[a[i]] = c[i];
		}
	}
	pre();
	while (q--) {
		cin >> x >> y >> z;
		if (x == 1) {
			if (y < n) {
				w1[a[y]] = z;
			} else {
				w2[a[y]] = z;
			}
		} else {
			cout << lca(y, z) << " " << w2[y] + w2[z] << ": "/* << endl*/;
			cout << min(lca(y, z), w2[y] + w2[z]) << endl;
		}
	}
	dfs(1);	
}
