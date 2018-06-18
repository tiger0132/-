#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
	int a, b, c;
	bool operator<(const node& rhs) const {
		if (b == rhs.b) {
			if (a == rhs.a) return c < rhs.c;
			return a < rhs.a;
		}
		return b < rhs.b;
	}
} rec[25004];

ll tree[4000006];
int spec;

void pushup(int x) {
	tree[x] = min(tree[x<<1], tree[x<<1|1]);
}

void build(int x, int l, int r) {
	if (l == r) {
		tree[x] = (l == spec ? 0 : 0xcfcfcfcfcfcfcfcf);
		return;
	}
	int mid = (l+r)>>1;
	build(x<<1, l, mid);
	build(x<<1|1, mid+1, r);
	pushup(x);
}

void modify(int i, int k, int x, int l, int r) {
	if (l == r) {
		tree[x] = k;
		return;
	}
	int mid = (l+r)>>1;
	if (i <= mid) modify(i, k, x<<1, l, mid);
	else modify(i, k, x<<1|1, mid+1, r);
	pushup(x);
}

ll query(int L, int R, int x, int l, int r) {
	if (L <= l && r <= R) return tree[x];
	int mid = (l+r)>>1, ans = 0;
	if (L <= mid) ans += query(L, R, x<<1, l, mid);
	if (mid < R) ans += query(L, R, x<<1|1, mid+1, r);
	return ans;
}

int n, l, r;

int main() {
	scanf("%d%d%d", &n, &l, &r); l++; spec = l; r += 2;
	build(1, l, r);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &rec[i].a, &rec[i].b, &rec[i].c);
		rec[i].a += 2; rec[i].b += 2;
	}
	sort(rec + 1, rec + n + 1);
	for (int i = 1; i <= n; i++) {
		ll tmp = query(rec[i].a-1, rec[i].b, 1, l, r) + rec[i].c;
		printf("%d: %lld\n", i, tmp);
		modify(rec[i].b, tmp, 1, l, r);
	}
	printf("%lld", query(l, r, 1, l, r));
}
