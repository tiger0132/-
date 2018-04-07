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

unsigned dp[4003];
int n;

int main() {
	scanf("%d", &n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - i]) % 2147483648u;
		}
	}
	printf("%d", dp[n] - 1); // 没改%u也能AC, emmm
	return 0;
}
*/