#include <bits/stdc++.h>
using namespace std;

int n, m, b, a, c;
int arr[105][105];
int sum[105][105];
int ans[105];

int main() {
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", arr[i] + j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = i; k <= min(i + b - 1, n); k++) {
				sum[i][j] += arr[k][j];
			}
			ans[j] = max(ans[j], sum[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			c += arr[j][i];
			if (sum[j][i] == ans[i]) {
				c -= arr[j][i];
				break;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		a += ans[i];
//		printf("%d\n", ans[i]);
	}
	printf("%d %d", a, c);
}
#if 0
3 4 2
0 1 1 1
1 0 1 1
1 0 0 1
#endif
