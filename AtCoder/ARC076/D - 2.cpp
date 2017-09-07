#include <bits/c++0x_warning.h>
#include <bits/stdc++.h>
using namespace std;

int x[100005], y[100005], par[100005];
vector<tuple<int, int, int>> edges;
int n, in[100005][2], z, cnt;

int dist(int x1, int y1, int x2, int y2) {
	return min(abs(x1 - x2), abs(y1 - y2));
}

int find(int index) {
	return par[index] == index ? index : par[index] = find(par[index]);
}

int merge(int p, int q) {
	return ((p = find(p)) != (q = find(q)) ? par[p] = q : 0);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		par[i] = i;
		cin >> in[i][0] >> in[i][1];
	}
	for (int i = 0; i < n; i++) {
		x[i] = y[i] = i;
	}
	sort(x, x + n, [](int u, int v) {
		return in[u][0] < in[v][0];
	});
	for (int i = 0; i < n - 1; i++) {
		edges.emplace_back(in[x[i + 1]][0] - in[x[i]][0], x[i], x[i + 1]);
	}
	sort(y, y + n, [](int u, int v) {
		return in[u][1] < in[v][1];
	});
	for (int i = 0; i < n - 1; i++) {
		edges.emplace_back(in[y[i + 1]][1] - in[y[i]][1], y[i], y[i + 1]);
	}
	sort(edges.begin(), edges.end());
	for (auto i : edges) { 
		if (find(get<1>(i)) != find(get<2>(i))) {
			merge(get<1>(i), get<2>(i));
			cnt += get<0>(i);
		}
	}
	cout << cnt; 
}
/*
6
8 3
4 9
12 19
18 1
13 5
7 6
*/
