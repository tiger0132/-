#include <bits/stdc++.h>
using namespace std;

vector<int> tree[305];
queue<int> output;
set<int> s[305];
int n, x, y, z;
int par[305];

void init(int index) {
	s[index].insert(index);
	for (int i : tree[index]) {
		if (i != par[index]) {
			par[i] = index;
			init(i);
			s[index].insert(s[i].begin(), s[i].end());
		}
	}
}

void dfs(int cur, int tar, int pre) {
	if (cur == tar) {
		return;
	} else if (!s[cur].count(tar) && par[cur] != pre) {
		output.push(cur);
		dfs(par[cur], tar, cur);
	} else {
		output.push(cur);
		for (int i : tree[cur]) {
			if (i != pre) {
				dfs(i, tar, cur);
			}
		}
	}
} 

int main() {
	cin >> n; 
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	init(1);
	int pos = 1;
	while (scanf("%d", &z) != EOF) {
		dfs(pos, z, 0);
		pos = z;
	}
	dfs(pos, 1, 0);
	output.push(1);//output.size() != 2 * n - 1
	cout << output.size() << endl;
	if (0) {
		cout << -1;
	} else {
		while (!output.empty()) {
			cout << output.front() << " ";
			output.pop();
		}
	}
} 
