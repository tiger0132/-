#include <bits/stdc++.h>
using namespace std;

int n, d, rec[102], ans = 0x3f3f3f3f;

int main() {
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec + i);
	}
	sort(rec + 1, rec + n + 1);
	for (int i = 1; i <= n; i++) {
		int j;
		for (j = i; j <= n; j++) {
			if (rec[j] > rec[i] + d) {
				break;
			}
		}
		ans = min(ans, n - j + i);
	}
	printf("%d", ans);
}