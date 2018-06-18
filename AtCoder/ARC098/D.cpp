#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int mod[200005];
int rec[200005];
int n, sum, x0r;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec + i);
	}
	for (int i = 1; i <= n; i++) {
		sum += rec[i];
		x0r ^= rec[i];
		mod[i] = x0r - sum;
		m[mod[i]]++;
		printf("(%d)", mod[i]);
		ans += m[mod[i]];
	}
	printf("%lld", ans);
	return 0;
}