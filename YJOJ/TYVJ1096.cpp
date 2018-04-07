#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
	scanf("%d%d", &a, &b);
	printf("%d", a + b);
}
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, rec[102], dp[10004];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec + i);
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= rec[i]; j--) {
			dp[j] += dp[j - rec[i]];
		}
	}
	printf("%d", dp[m]);
	return 0;
}
*/