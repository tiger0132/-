#include <bits/stdc++.h>
using namespace std;

vector<int> child[100005];
int cnt[100005];
int n, k, ans;

void dfs(int x, int dep = 1) {
	cnt[dep]++;
	for (int i = 0; i < child[x].size(); i++) {
		dfs(child[x][i], dep + 1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &k);
		child[k].push_back(i);
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		ans += (cnt[i] & 1);
	}
	printf("%d", ans);
	return 0;
}