#include <bits/stdc++.h>
using namespace std;

int a[1000006];
int n, p, ans;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	p = 2;
	sort(a+1, a+n+1, greater<int>());
	for (int i = 1; i <= n; i++, p++) {
		while (i < p && a[p] == a[i] && p <= n) p++;
		if (p > n) continue;
		ans++;
	}
	printf("%d", ans);
	return 0;
}