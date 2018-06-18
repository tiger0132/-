#include <bits/stdc++.h>
using namespace std;

int school[102], home[102];
int gph[102][102], need;
int match[102];
bool vis[102];
int n, t, ans;

int dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (gph[x][i] && !vis[i]) {
			vis[i] = 1;
			if (!match[i] || dfs(match[i])) {
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(gph, 0, sizeof gph); need = ans = 0;
		memset(match, 0, sizeof match);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", school+i);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", home+i);
			home[i] &= school[i];
			if (school[i] && !home[i]) need++;
 		}
		need = n - need;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", gph[i]+j);
			}
			if (school[i]) gph[i][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			if ((!school[i] || !home[i]) && !dfs(i)) {
				puts("T_T");
				goto end;
			}
		}
		puts("^_^");
		end:;
	}
	return 0;
}