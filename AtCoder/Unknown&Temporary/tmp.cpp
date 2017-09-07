#include <bits/stdc++.h>
using namespace std;

vector<int> tree[2005];
int ans, n, k, a, b;

int main() {
	cin >> n >> k;
	ans = 0x3f3f3f3f;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for (int i = 1; i < n; i++) {
		int dep[2005] {}, cnt = 0;
		bool vis[2005] {};
		queue<int> bfs;
		bfs.push(i);
		while (!bfs.empty()) {
			int index = bfs.front();
			bfs.pop();
			vis[index] = true;
			if (dep[index] > k / 2) {
				cnt++;
			}
			for (int i : tree[index]) {
				if (!vis[i]) {
					dep[i] = dep[index] + 1;
					bfs.push(i);
				}
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;
} 
/*
6 2
1 2
3 2
4 2
1 6
5 6
*/
