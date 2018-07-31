#include <bits/stdc++.h>
using namespace std;

int n, k, pos, ans;
int rec[202];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	while (pos < n && rec[pos+1] <= k) pos++;
	ans = pos;
	for (int i = n; i > pos; i--) {
		if (rec[i] > k) break;
		ans++;
	}
	printf("%d", ans);
	return 0;
}