#include <bits/stdc++.h>
using namespace std;

int A[3003], B[3003];
int nxt[3003][3003];
int dp[3003][3003];
int n, m, ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", A+i);
	for (int i = 1; i <= m; i++) scanf("%d", B+i);
	memset(nxt[m+1], 63, sizeof nxt[m+1]);
	for (int i = m; i >= 1; i--) {
		memcpy(nxt[i], nxt[i+1], sizeof nxt[i+1]);
		if (i != m) nxt[i][B[i+1]] = i+1;
	} 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], 1);
				for (int a = i+1; a <= n; a++) {
					if (A[a] <= A[i]) continue;
					int b = nxt[j][A[a]];
					if (b == 0x3f3f3f3f) continue;
					dp[a][b] = max(dp[a][b], dp[i][j]+1);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d", ans);
}

#if 0

4 3
1 5 3 4
1 5 4

3 4
2 1 5
1 2 1 5

#endif
