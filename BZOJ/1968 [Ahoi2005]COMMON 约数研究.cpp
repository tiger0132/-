#include <bits/stdc++.h>
using namespace std;

long long ans;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ans += n / i;
	}
	printf("%lld", ans);
}