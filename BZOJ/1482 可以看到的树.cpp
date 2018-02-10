#include <bits/stdc++.h>
using namespace std;

int t, n, m;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int ans = m;
		for (int i = 2; i <= n; i++) {
			ans += m - m / i + 1;
		}
		printf("%d\n", ans * 4);
	}
}