#include <bits/stdc++.h>
using namespace std;

vector<int> gph[1024];
int dp[1024][1024];
int sc[1024];
int n, m, k;

void dfs(int x) {
    for (int i = 1; i <= m; i++) dp[x][i] = sc[x];
    for (int i = 0; i < gph[x].size(); i++) {
        int nx = gph[x][i];
        dfs(nx);
        for (int j = m; j; j--) {
            for (int k = 0; k < j; k++) {
                dp[x][j] = max(dp[x][j], dp[x][j-k] + dp[nx][k]);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++) {
        scanf("%d%d", &k, sc + i);
        gph[k].push_back(i);
    }
    m++;
    dfs(0);
    printf("%d", dp[0][m]);
    return 0;
}