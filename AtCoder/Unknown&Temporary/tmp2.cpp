#include <bits/stdc++.h>
using namespace std;

vector<int> gph[2048]; 
int n, k, x, y, ans;

int dfs(int cur, int par, int dep, int lim) {
	int ret = 1;
	if (dep != lim) {
		for (int i : gph[cur]) {
			if (i != par) {
				ans += dfs(i, cur, dep + 1, lim); 
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		gph[x].push_back(y);
		gph[y].push_back(x);
	}
	if (k & 1) {
		for (int i = 1; i <= n; i++) {
			ans = max(ans, dfs(i, -1, 0, k / 2));
		}
	} else {
		for (int u = 1; u <= n; u++) {
			for (int v : gph[u]) {
				ans = max(ans, dfs(u, v, 0, k / 2) + dfs(v, u, 0, k / 2));
			}
		}
	}
	cout << n - ans;
}

/*
6 5
1 2
3 2
4 2
1 6
5 6
*/
