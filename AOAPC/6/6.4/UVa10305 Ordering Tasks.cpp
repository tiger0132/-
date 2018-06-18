#include <bits/stdc++.h>
using namespace std;

int gph[102][102];
int n, m, a, b;
stack<int> st;
int vis[102];

int dfs(int x) {
	vis[x] = 1;
	for (int i = 1; i <= n; i++) {
		if (gph[x][i] && !vis[i]) {
			dfs(i);
		}
	}
	st.push(x);
}

int main() {
	while (scanf("%d%d", &n, &m) && (n || m)) {
		memset(vis, 0, sizeof vis);
		memset(gph, 0, sizeof gph);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d", &a, &b);
			gph[a][b] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
			}
		}
		while (!st.empty()) {
			printf("%d ", st.top()); st.pop();
		}
		puts("");
	}
}