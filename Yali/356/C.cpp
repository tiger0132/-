#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
	int to, next;
} e[10005];

int head[1003], cnt, n, m;
int dp[1003][1003];

int val[1003], size[1003], dis[1003][1003];
bool vis[1003][1003];
int tmp[1003];

int add(int& x, int y) {
	x = ((ll)x + y) % 1000000007;
}

int dfs(int x, int par) {
    dis[x][size[x]++] = val[x];
    vis[x][val[x]] = true;
	dp[x][val[x]] = 1;
    for (int i = head[x]; i; i = e[i].next) {
        int nx = e[i].to;
        if (nx == par) continue;
        dfs(nx, x);
        memset(tmp, 0, m << 2);
        for (int j = size[x]-1; j >= 0; j--) {
            for (int k = 0; k < size[nx]; k++) {
                int a = dis[x][j], b = dis[nx][k];
                add(tmp[a^b], (ll)dp[x][a] * dp[nx][b] % 1000000007);
                if (!vis[x][a^b]) dis[x][size[x]++] = a^b, vis[x][a^b] = true;
            }
        }
        for (int j = 0; j < m; j++) add(dp[x][j], tmp[j]);
    }
}

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = ++cnt;
	e[++cnt] = (edge){x, head[y]}; head[y] = ++cnt;
}

int t, x, y;

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(head, 0, (n+1) << 2); cnt = 0;
		memset(size, 0, (n+2) << 2);
		for (int i = 0; i <= n; i++) {
			memset(dp[i], 0, m << 2);
			memset(vis[i], 0, m << 2);
		}
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", val+i);
		}
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			addedge(x, y);
		}
        dfs(1, -1);
        for (int i = 0; i < m; i++) {
            int ans = 0;
            for (int j = 1; j <= n; j++) add(ans, dp[j][i]);
            printf("%d%c", ans, i == m-1 ? '\n' : ' ');
        }
	}
	return 0;
}