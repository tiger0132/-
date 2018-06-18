#include <bits/stdc++.h>
using namespace std;

double c, ans;
int n;

int main() {
	scanf("%d", &n);
	c = 420000. / n;
	for (int i = 1; i <= n; i++) {
		ans += c;
		c *= ((i<<1) - 1.) / (i<<1);
	}
	printf("%.2f", ans);
	return 0;
}