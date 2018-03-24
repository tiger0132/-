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
//	printf("!%p (result[%d]: %d) += %d\n", &result, x, result[x], offset);
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
		int l[2] = {1, 1}, r[2] = {0, 0};
		for (int i = 0; i < m; i++) {
//			printf("%d:\n", i & 1);
			while (r[i&1] < q[i].r) extend(rec[++r[i&1]], 1, cnt[i & 1]);
			while (r[i&1] > q[i].r) extend(rec[r[i&1]--], -1, cnt[i & 1]);
			while (l[i&1] > q[i].l) extend(rec[--l[i&1]], 1, cnt[i & 1]);
			while (l[i&1] < q[i].l) extend(rec[l[i&1]++], -1, cnt[i & 1]);
			if (i & 1) for (int j = 1; j < n; j++) {
				*q[i].ans += cnt[0][j] * cnt[1][n - j];
			}
		}
		for (int i = 1; i <= _; i++) {
			printf("%d\n", ans[i]);
		}
	}
}

#if 0
6
4
1 2 3 1 2 3
5
1 3 4 6
1 2 5 6
1 3 5 6
2 3 5 6
1 4 5 6
#endif
