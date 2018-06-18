#include <bits/stdc++.h>
using namespace std;

int n, m, tree[2000006], rec[500005];

void pushup(int x) {
	tree[x] = tree[x<<1] + tree[x<<1|1];
}

void build(int x, int l, int r) {
	// printf("(%d, %d, %d)\n", x, l, r);
	if (l == r) {
		tree[x] = rec[l];
		return;
	}
	int mid = (l+r)>>1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	pushup(x);
}

void update(int i, int k, int x, int l, int r) {
	if (l == r) {
		tree[x] += k;
		return;
	}
	int mid = (l+r)>>1;
	if (i <= mid) update(i, k, x<<1, l, mid);
	else update(i, k, x<<1|1, mid+1, r);
	pushup(x);
}

int query(int i, int x, int k, int l, int r) {
	if (l == r) return tree[x];
	int mid = (l+r)>>1;
	if (i <= mid) return query(i, x<<1, k, l, mid);
	else query(i, x<<1|1, k, mid+1, r);
}

int query2(int L, int R, int x, int l, int r) {
	// printf("(%d, %d, %d)\n", x, l, r);
	if (L <= l && r <= R) return tree[x];
	int mid = (l+r)>>1, ans = 0;
	if (L <= mid) ans += query2(L, R, x<<1, l, mid);
	if (mid < R) ans += query2(L, R, x<<1|1, mid+1, r);
	return ans;
}

int op, x, y;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			update(x, y, 1, 1, n);
		} else {
			printf("%d\n", query2(x, y, 1, 1, n));
		}
	}
	return 0;
}