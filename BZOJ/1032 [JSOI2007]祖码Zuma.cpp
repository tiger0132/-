#include <bits/stdc++.h>
using namespace std;

int dp[512][512];
int col[512];
int cnt[512];
int t, p, x;
int n = 1;

int main() {
	scanf("%d%d", &t, col+1);
	while (++cnt[n], --t) {
		scanf("%d", &p);
		if (col[n] != p) {
			col[++n] = p;
		}
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 2 ^ (cnt[i] > 2);
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			dp[i][j] = 0x3f3f3f3f;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
			}
			if (col[i] == col[j]) {
				dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dp[i][j]);
		}
		puts("");
	}
	printf("%d", dp[1][n]);
} 
