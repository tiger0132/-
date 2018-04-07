#include <bits/stdc++.h>
using namespace std;

int perm[5] = {0, 1, 2, 3, 4};
int n, ans = 0x3f3f3f3f;
char rec[9][102][102];
int dif[9];

int main() {
	scanf("%d", &n);
	for (int k = 1; k <= 4; k++) {
		for (int i = 1; i <= n; i++) {
			scanf("%s", rec[k][i] + 1);
			for (int j = 1; j <= n; j++) {
				rec[k][i][j] ^= 48;
				dif[k] += ((i + j) % 2 != rec[k][i][j]);
			}
		}
	}
	do {
		int ret = 0;
		for (int i = 1; i <= 4; i++) {
			// printf("%d ", perm[i]);
			ret += (i % 2 ? dif[perm[i]] : n * n - dif[perm[i]]);
		}
		// printf(": %d\n", ret);
		ans = min(ans, ret);
	} while (next_permutation(perm + 1, perm + 5));
	printf("%d\n", ans);
	return 0;
}