#include <bits/stdc++.h>
using namespace std;

int n, m, blockSize, src[50004], ans[200005], cnt[1000006];

struct query {
	int l, r, *ans;
	bool operator<(const query& x) const {
		if (l / blockSize == x.l / blockSize) return r < x.r;
		return l / blockSize < x.l / blockSize;
	}
} q[200005];

int extend(int x, int offset) {
	if (~offset) return 1 == ++cnt[x];
	else return -!--cnt[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", src+i);
	}
	blockSize = ceil(sqrt(n));
	scanf("%d", &m);
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