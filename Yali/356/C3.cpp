#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int to, next;
} e[1006];

int head[1003], cnt;

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y]}; head[y] = cnt;
}

int v[1003], n, m, t;
int val[1003][1003];
int vis[1003][1003];
int dp[1003][1003];
int size[1003];
int tmp[1003];

void add(int &x, int y) {
    x = ((ll)x + y) % 1000000007;
}

void dfs(int x, int par) {
    val[x][size[x]++] = v[x];
    vis[x][v[x]] = true;
    dp[x][v[x]] = 1;
    for (int i = head[x]; i; i = e[i].next) {
        int nx = e[i].to;
        if (nx == par) continue;
        dfs(nx, x);
        memset(tmp, 0, sizeof tmp);
        for (int j = size[x]-1; j >= 0; j--) {
            for (int k = 0; k < size[nx]; k++) {
                int p = val[x][j], q = val[nx][k];
                add(tmp[p^q], (ll)dp[x][p] * dp[nx][q] % 1000000007);
                if (!vis[x][p^q]) val[x][size[x]++] = p^q, vis[x][p^q] = true;
            }
        }
        for (int j = 0; j < m; j++) add(dp[x][j], tmp[j]);
    }
}

int x, y;

int main() {
	for (scanf("%d", &t); t--; ) {
		scanf("%d%d", &n, &m);
		memset(head, 0, sizeof head); cnt = 0;
		memset(size, 0, sizeof size);
		memset(vis, 0, sizeof vis);
		memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) {
			scanf("%d", v+i);
		}
        for (int i = 1; i < n; i++) {
			scanf("%d%d", &x, &y);
			addedge(x, y);
		}
        dfs(1, -1);
        for (int k = 0; k < m; k++) {
            int ans = 0;
            for (int i = 1; i <= n; i++) add(ans, dp[i][k]);
            printf("%d%c", ans, k==m-1?'\n':' ');
        }
    }
    return 0;
}
