#include <bits/stdc++.h>
using namespace std;

int f(int x) {
	int ret = 1;
	while (x) {
		ret *= max(1, x % 10);
		x /= 10;
	}
	return ret;
}

int g(int x) {
	if (x < 10) return x;
	else return g(f(x));
}

int cnt[1000006][11];
int n, l, r, q;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 1000000; i++) {
		for (int j = 1; j <= 9; j++) cnt[i][j] = cnt[i - 1][j];
		int t = g(i);
		cnt[i][t]++;
		// printf("%d:%d\n ", i, t);
	}
	// for (int i = 1; i <= 9; i++) {
	// 	for (int j = 1; j <= 100; j++) {
	// 		printf("%d ", cnt[i][j]);
	// 	} puts("");
	// }
	while (n--) {
		scanf("%d%d%d", &l, &r, &q);
		printf("%d\n", cnt[r][q] - cnt[l-1][q]);
	}
}