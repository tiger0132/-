#include <bits/stdc++.h>
using namespace std;

int n, ans = 1, a[3003], b[3003], dp[3003][3003];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b+i);
		// dp[i][0] = 1;
	}
	// a[0] = b[0] = 0xcfcfcfcf;
	for (int i = 1; i <= n; i++) {
		int ax = (b[0] < a[i]) * dp[i-1][0];
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) dp[i][j] = ax + 1;
			else dp[i][j] = dp[i-1][j];
			if (b[j] < a[i]) ax = max(ax, dp[i-1][j]);
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d", ans);
	return 0;
}