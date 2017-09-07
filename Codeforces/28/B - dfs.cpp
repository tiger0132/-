#include <bits/stdc++.h>
using namespace std;

const int size = 128;

int fav[size], index[size];
int connect[size][size];
int visited[size];
int n, x;

bool dfs(int v, int tar) {
	if (v == tar) {
		return true;
	}
	visited[v] = 1;
	bool ret = false;
	for (int i = 1; i <= n; i++) {
		if (connect[v][i] && !visited[i]) {
			ret |= dfs(i, tar);
		}
	}
	visited[v] = 0;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		index[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> fav[i];
		if (i - fav[i] >= 1) {
			connect[i][i - fav[i]] = connect[i - fav[i]][i] = 1;
		}
		if (i + fav[i] <= n) {
			connect[i][i + fav[i]] = connect[i + fav[i]][i] = 1;
		}
		connect[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (!dfs(i, index[i])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
} 
