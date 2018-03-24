#include <bits/stdc++.h>
using namespace std;

int n, m, k, blockSize, src[50004], ans[50004], cnt[50004];

struct query {
	int l, r, *ans;
	bool operator<(const query& x) const {
		if (l / blockSize == x.l / blockSize) return r < x.r;
		return l / blockSize < x.l / blockSize;
	}
} q[50004];

int extend(int x, int offset) {
	if (~offset) return 2 * ++cnt[x] - 1; // 1
	else return 1 - 2 * cnt[x]--;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", src+i);
	}
	blockSize = ceil(sqrt(n));
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].ans = ans+i;
	}
	sort(q + 1, q + m + 1);
	int l = 1, r = 0, lans = 0;
	for (int i = 1; i <= m; i++) {
		while (r < q[i].r) lans += extend(src[++r], 1);
		while (r > q[i].r) lans += extend(src[r--], -1);
		while (l > q[i].l) lans += extend(src[--l], 1);
		while (l < q[i].l) lans += extend(src[l++], -1);
		*q[i].ans = lans;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
}