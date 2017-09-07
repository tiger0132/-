#include <bits/stdc++.h>
using namespace std;

struct edge {
	int x, y, a, b; 
	bool operator <(const edge& val) {
		return x < val.x;
	}
} e;

struct dsu {
	int par[256];
	int find(int x) {
		return par[x] ? par[x] = find(par[x]) : x;
	}
	int merge(int x, int y) {
		return find(x) != find(y) ? par[find(x)] = find(y) : 0;
	}
} d;

int n, m, a, b, p, q, cnt, __b;
vector<pair<int, int>> tree;
vector<edge> graph;
bool book[256];

void dfs(int index, int par) {
	for (auto& i : tree[index]) {
		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> p >> q;
	while (m--)  {
		cin >> e.x >> e.y >> e.a >> e.b;
		graph.push_back(e);
	}
	for (edge i : graph) {
		if (d.merge(i.x, i.y)) {
			tree[i.x].push_back(make_pair(i,y, i.a));
			tree[i.y].push_back(make_pair(i,x, i.a));
			cnt++;
		} else {
			dfs(i.x, -1);
			for (int i = 0)
		}
	}
} 
