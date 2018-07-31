#include <bits/stdc++.h>
using namespace std;

long long rec[200005], ans;
int mod[200005];
int n, m, k, x;
set<int> q;
int start;

int main() {
	scanf("%d%d", &n, &m);
	k = n / m;
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", rec+i);
		mod[rec[i] % m]++;
	}
	for (int i = 0; i < m; i++) {
		mod[i] -= k;
		if (mod[i] < 0) q.insert(i);
	}
	for (int i = 1; i <= n; i++) {
		if (mod[rec[i] % m] > 0) {
			set<int>::const_iterator it = q.lower_bound(rec[i] % m);
			if (it == q.end()) it = q.begin();
			if (!++mod[x = *it]) q.erase(it);
			mod[rec[i] % m]--;
			ans += (m + x - rec[i] % m) % m;
			rec[i] += (m + x - rec[i] % m) % m;
		}
	}
	printf("%I64d\n", ans);
	for (int i = 1; i <= n; i++) {
		printf("%I64d ", rec[i]);
	}
	return 0;
}