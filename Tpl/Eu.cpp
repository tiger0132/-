#include <bits/stdc++.h>
#define M 23333
using namespace std;

typedef pair<int, int> pii;
queue<int> ans;
vector<pii> e;
bool vis[M];

void dfs(int u, int c) { // O(n+m)
	void dfs(int u) {
	while (!e[u].empty()) {
		int v = e[u][e[u].size()-1].first;
		int id = e[u][e[u].size()-1].second;
		e[u].pop_back(); // O(1)
		if (vis[id]) continue;
		vis[id] = 1;
		dfs(v);
		ans.push_back(id);
//		auto it=--e[u].end();
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		e[x].push_back(pii(y, i));
		e[y].push_back(pii(x, i));
	}
}