#include <bits/stdc++.h>
using namespace std;

int tree[305][305];
queue<int> output;
int n, x, y, z;
int pos = 1;

void dfs(int cur, int tar) {
	if (cur != tar) {
		for (int i = 1; i <= n; i++) {
			if (tree[cur][i] == 1 && tree[i][tar] < tree[cur][tar]) {
				output.push(i);
				dfs(i, tar);
			}
		}
	}
} 

int main() { 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				tree[i][j] = 0x3f3f3f3f;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		tree[x][y] = tree[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				tree[i][j] = min(tree[i][j], tree[i][k] + tree[k][j]);
			}
		}
	}
	output.push(1);
	while (scanf("%d", &z) != EOF) {
		dfs(pos, z);
		pos = z;
	}
	dfs(pos, 1);
	if (output.size() != 2 * n - 1) {
		cout << -1;
	} else {
		while (!output.empty()) {
			cout << output.front() << " ";
			output.pop();
		}
	}
}
