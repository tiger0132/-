#include <bits/stdc++.h>
using namespace std;

vector<int> tree[305];
queue<int> output;
int n, x, y, z;

int dfs(int cur, int tar, int par) {
	if (cur == tar) {
		return 1;
	}
	for (int i : tree[cur]) {
		if (i == par) {
			continue;
		}
		if (dfs(i, tar, cur)) {
			output.push(i);
			return 1;
		}
	}
	return 0;
}

int main() { 
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	int pos = 1;
	while (scanf("%d", &z) != EOF) {
		dfs(z, pos, 0);
		pos = z;
	}
	dfs(1, pos, 0);
	output.push(1);
	if (output.size() != 2 * n - 1) {
		cout << -1;
	} else {
		while (!output.empty()) {
			cout << output.front() << " ";
			output.pop();
		}
	}
}
