#include <bits/stdc++.h>
using namespace std;

int blockSize;

struct query {
	int l, r, *ans;
	bool operator<(const query& x) const {
		if (l / blockSize == x.l / blockSize) return r < x.r;
		return l / blockSize < x.l / blockSize;
	}
} q[60004];

int cnt[2][30004];
int rec[30004];
int ans[30004];
int n, m, _, k;

void extend(int x, int offset, int *result) {
	result[x] += offset;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", rec + i);
		}
		scanf("%d%d", &k, &m);
		blockSize = ceil(sqrt(n));
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &q[2 * i].l, &q[2 * i].r, &q[2 * i + 1].l, &q[2 * i + 1].r);
			q[2 * i + 1].ans = &ans[i + 1];
		}
		_ = m; m <<= 1;
		sort(q, q + m); // [0, 2m)
		int l = 1, r = 0;
		for (int i = 0; i < m; i++) {
			while (r < q[i].r) extend(rec[++r], 1, cnt[i & 1]);
			while (r > q[i].r) extend(rec[r--], -1, cnt[i & 1]);
			while (l > q[i].l) extend(rec[--l], 1, cnt[i & 1]);
			while (l < q[i].l) extend(rec[l++], -1, cnt[i & 1]);
			if (i & 1) for (int j = 1; j < n; j++) {
				*q[i].ans += cnt[i ^ 1][j] * cnt[i][n - j];
			}
		}
		for (int i = 1; i <= _; i++) {
			printf("%d\n", ans[i]);
		}
	}
}