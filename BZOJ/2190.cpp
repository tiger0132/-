#include <bits/stdc++.h>
using namespace std;

long long ans;
int n;
 
int main() {
	scanf("%d", &n);
	ans = n + 1;
	for (int i = 3; i <= n; i++) {
		ans += n - n / i - 1;
	}
	printf("%lld", ans);
	return 0;
}