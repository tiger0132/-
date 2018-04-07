#include <bits/stdc++.h> // CE++
using namespace std;

const int oo = 998244353;

int dp[303][303];
int d[303][303];
int s[303][303];
int a[303];
int n, _;

int sm(int x) {
	return (x - 1) % n + 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", s[i]+1);
		_ += s[i][1];
	}
	for (int j = 2; j <= n; j++) {
		for (int i = 1; i < n; i++) {
			s[i][j] = s[i][1] + s[sm(i + 1)][j - 1];
		}
	}
	for (int j = 2; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			int minx = oo;
			for (int k = 1; k < j; k++) {
				if (i + k > n) continue;
				int ti = dp[i][k] + dp[sm(i + k)][j - k];
				if (ti < minx) {
					minx = ti;
					d[i][j] = k;
				}
			}
			dp[i][j] = minx + s[i][j];
		}
	}
	int minx = oo, mini = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i][n] < minx) {
			minx = dp[i][n];
			mini = i;
		}
	}
	printf("%d\n", minx);
	return 0;
}