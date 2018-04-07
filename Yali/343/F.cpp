#include <bits/stdc++.h>
using namespace std;

long long dp[102][91];
long long n;
int k, ans;

int main() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 63; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
		}
	}
	while (~scanf("%d%lld", &k, &n) && k) {
		ans = 0xcfcfcfcf;
		for(int i = 1; i <= 63; i++) {
			if (dp[k][i] >= n) {
				ans = i;
				break;
			}
		}
		if (ans >= 0) printf("%d\n", ans);
		else puts("More than 63 trials needed.");
	}
}