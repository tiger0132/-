#include<cstdio>
#include <bits/stdc++.h>
using namespace std;

int gph[61][61], n, ans, _;

int main() {
	while (scanf("%d", &n), n) {
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				scanf("%d", gph[i]+j);
				gph[j][i] = gph[i][j];
			}
		}
		ans = gph[1][2];
		for (int i = 3; i <= n; i++) {
			_ = 0x3f3f3f3f;
			for (int j = 2; j < i; j++) {
				_ = min(_, (gph[1][i] + gph[j][i] - gph[1][j]) >> 1);
			}
			ans += _;
		}
		printf("%d\n", ans);
	}
	return 0;
}