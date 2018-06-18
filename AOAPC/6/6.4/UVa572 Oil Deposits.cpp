#include <bits/stdc++.h>
using namespace std;

const int N = 102;

int n, m, ans;
char rec[N][N];

void dfs(int x, int y, int c) {
	rec[x][y] = c;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int nx = x + i;
			int ny = y + j;
			if ((i || j) && rec[nx][ny] == '@') {
				dfs(x + i, y + j, c);
			}
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &m) && n && m) {
		memset(rec, 0, sizeof rec);
		for (int i = 0; i < n; i++) {
			scanf("%s", rec[i]);
		}
		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (rec[i][j] == '@') {
					dfs(i, j, ++ans);
				}
			}
		}
		printf("%d\n", ans);
	}
}