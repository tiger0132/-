#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		ans = max(ans, min(x - 1, 1000000 - x));
	}
	printf("%d", ans);
}