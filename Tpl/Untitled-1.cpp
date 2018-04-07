#include<cstdio>
#include<ctime>
#include <bits/stdc++.h>
using namespace std;

int t, n, m;
char objects[128][111];

int vis[2048][2048], d[2048][2048];
int cnt[2048][2048];

int dfs(int s, int a) {
	if (cnt[s][a] <= 1) return 0;
	if (cnt[s][a] == 2) return 1;
	int& ans = d[s][a];
	if (vis[s][a] == t) return ans;
	vis[s][a] = t;
	ans = m;
	for (int k = 0; k < m; k++) {
		if (!(s & (1<<k))) {
			int s2 = s|(1<<k), a2 = a|(1<<k);
			if (cnt[s2][a2] >= 1 && cnt[s2][a] >= 1) {
				int need = max(dfs(s2, a2),	dfs(s2, a)) + 1;
				ans = min(ans, need);
			}
		}
	}
	return ans;
}

void init() {
	for (int s = 0; s < (1<<m); s++) {
		for (int a = s; a; a = (a-1)&s){
			cnt[s][a] = 0;
		}
		cnt[s][0] = 0;
	}
	for (int i = 0; i < n; i++) {
		int state = 0;
		for (int f = 0; f < m; f++) {
			if (objects[i][f] == '1') state |= (1<<f);
		}
		for (int s = 0; s < (1<<m); s++) {
			cnt[s][s & state]++;
		}
	}
}


int main() {
	memset(vis, 0, sizeof vis);
	while (scanf("%d%d", &m, &n) == 2 && n) {
		t++;
		for (int i = 0; i < n; i++) scanf("%s", objects[i]);
		init();
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}