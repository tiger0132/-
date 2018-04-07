#include <bits/stdc++.h>
using namespace std;

int n, k, a[100005], t[100005];
int psum[100005], sum, ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", t+i);
	}
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i-1] + a[i] * !t[i];
		sum += a[i] * t[i];
	}
	for (int i = 0; i <= n - k + 1; i++) {
		ans = max(ans, psum[i + k] - psum[i]);
	}
	printf("%d", ans + sum);
	return 0;
}