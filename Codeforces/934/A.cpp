#include <bits/stdc++.h>
using namespace std;

long long ans;
int a[55];
int b[55];
int n, m;

int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	ans = 0x7fffffffffffffff;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", b+i);
	}
	for (int i = 1; i <= n; i++) {
		long long lans = -11111111111111111;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (i != j) {
					lans = max(lans, (long long)a[j] * (long long)b[k]);
				}
			}
		}
		ans = min(ans, lans);
	}
	printf("%I64d", ans);
} 

#if 0
3 3
-1 -2 9
9 8 7
#endif