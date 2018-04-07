#include <bits/stdc++.h>
using namespace std;

unsigned dp[31][16][11][10][6];
int n, rec[6];

int main() {
	while (~scanf("%d", &n) && n) {
		memset(rec, 0, sizeof rec);
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) {
			scanf("%d", rec + i);
		}
		dp[0][0][0][0][0] = 1;
		for (int a = 0; a <= rec[1]; a++) {
			for (int b = 0; b <= rec[2]; b++) {
				for (int c = 0; c <= rec[3]; c++) {
					for (int d = 0; d <= rec[4]; d++) {
						for (int e = 0; e <= rec[5]; e++) {
							if (a < rec[1]) dp[a+1][b][c][d][e] += dp[a][b][c][d][e];
							if (b < rec[2] && a > b) dp[a][b+1][c][d][e] += dp[a][b][c][d][e];
							if (c < rec[3] && a > c && b > c) dp[a][b][c+1][d][e] += dp[a][b][c][d][e];
							if (d < rec[4] && a > d && b > d && c > d) dp[a][b][c][d+1][e] += dp[a][b][c][d][e];
							if (e < rec[5] && a > e && b > e && c > e && d > e) dp[a][b][c][d][e+1] += dp[a][b][c][d][e];
						}
					}
				}
			}
		}
		printf("%u\n", dp[rec[1]][rec[2]][rec[3]][rec[4]][rec[5]]);
	}
	return 0;
}