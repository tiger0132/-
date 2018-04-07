#include <bits/stdc++.h>
using namespace std;

int n, m, rec[100005];
int mrec[100005];
int smax[100005];
long long ans;
int t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec + i);
	}
	for (int i = 1; i <= n; i++) {
		smax[i] = max(smax[i - 1], rec[i]);
	}
	for (int i = n; i >= 1; i--) {
		mrec[i] = t = max(smax[i], t - 1);
	}
	for (int i = 1; i < n; i++) {
		mrec[i] = mrec[i + 1] - mrec[i];
	}
	for (int i = 1; i <= n; i++) {
		ans += m - rec[i];
		m += mrec[i];
	}
	printf("%lld", ans);
	return 0;
}