#include <bits/stdc++.h>
using namespace std;

int lis[2003][2003];
int dp[2003][2003];
int a[2003];
int n, ans;
int x;

int main(int argc, char *argv[]) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			lis[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			
		}
	}
	a[n+1] = 0x3f3f3f3f;
	for (int i = 1; i <= n-1; i++) {
		for (int j = i+1; j <= n; j++) {
			dp[i][j] = max(dp[i][j-1] + (a[i-1] <= a[j]), dp[i+1][j] + (a[i] <= a[j+1]));
			ans = max(ans, dp[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", dp[i][j]);
		} puts("");
	}
	printf("%d", ans);
	while (1);
}  