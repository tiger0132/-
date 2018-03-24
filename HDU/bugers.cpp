#include <bits/stdc++.h>
using namespace std;

int blockSize;

struct query {
	int l, r, offset, id, *ans;
	bool operator<(const query& x) const {
		if (l / blockSize == x.l / blockSize) return r < x.r;
		return l / blockSize < x.l / blockSize;
	}
	void set(int L, int R, int OFFSET, int ID, int *ANS) {
		l = L, r = R, offset = OFFSET, id = ID, ans = ANS;
	}
} q[120005];

int cnt[120005];
int rec[120005];
int ans[120005];
int out[30004];
int l, r, u, v;
int n, m, k;

int extend(int x, int offset) {
	cnt[x] += offset;
	if (k - x >= 1 && k - x <= n) return cnt[x] * offset;
	return 0;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", rec + i);
		}
		scanf("%d%d", &k, &m);
		blockSize = ceil(sqrt(n));
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &l, &r, &u, &v);
			q[4 * i].set(l, v, 1, i, &arr[4 * i]);
			q[4 * i + 1].set(r + 1, v, -1, i, &arr[4 * i + 1]);
			q[4 * i + 2].set(l, u - 1, -1, i, &arr[4 * i + 2]);
			q[4 * i + 3].set(r + 1, u - 1, 1, i, &arr[4 * i + 3]);
		}
		sort(q, q + 4 * m); // [0, 4m)
		int l = 1, r = 0, ans = 0;
		for (int i = 0; i < 4 * m; i++) {
			while (r < q[i].r) ans += extend(rec[++r], 1);
			while (r > q[i].r) ans += extend(rec[r--], -1);
			while (l > q[i].l) ans += extend(rec[--l], 1);
			while (l < q[i].l) ans += extend(rec[l++], -1);
			if (i % 4 == 3) {

			}
		}
		for (int i = 1; i <= m; i++) {
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