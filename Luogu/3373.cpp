#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int p;

struct node *newNode();

struct node {
	ll add, mul, val;
	node *lc, *rc;
	void pushup() {
		val = (lc->val + rc->val) % p;
	}
	void pushdown(int l, int r) {
		int mid = (l+r)>>1;
		lc->val = (lc->val * mul + add * (mid - l + 1)) % p;
		rc->val = (rc->val * mul + add * (r - mid)) % p;
		lc->mul = lc->mul * mul % p;
		rc->mul = rc->mul * mul % p;
		lc->add = (lc->add * mul + add) % p;
		rc->add = (rc->add * mul + add) % p;
		add = 0; mul = 1;
	}
	void build(int l, int r, int *arr) {
		add = 0; mul = 1;
		if (l == r) {
			val = arr[l];
			return;
		}
		int mid = (l+r)>>1;
		(lc = newNode())->build(l, mid, arr);
		(rc = newNode())->build(mid+1, r, arr);
		pushup();
	}
	void update1(int L, int R, int l, int r, int x) {
		if (L <= l && r <= R) {
			add = (add + x) % p;
			val = (val + x * (r - l + 1)) % p;
			return;
		}
		int mid = (l+r)>>1;
		pushdown(l, r);
		if (L <= mid) lc->update1(L, R, l, mid, x);
		if (mid < R) rc->update1(L, R, mid+1, r, x);
		pushup();
	}
	void update2(int L, int R, int l, int r, int x) {
		if (L <= l && r <= R) {
			val = val * x % p;
			add = add * x % p;
			mul = mul * x % p;
			return;
		}
		int mid = (l+r)>>1;
		pushdown(l, r);
		if (L <= mid) lc->update2(L, R, l, mid, x);
		if (mid < R) rc->update2(L, R, mid+1, r, x);
		pushup();
	}
	ll query(int L, int R, int l, int r) {
		if (L <= l && r <= R) {
			return val;
		}
		int mid = (l+r)>>1; ll ret = 0;
		pushdown(l, r);
		if (L <= mid) ret = (ret + lc->query(L, R, l, mid)) % p;
		if (mid < R) ret = (ret + rc->query(L, R, mid+1, r)) % p;
		return ret;
	}
} pool[500005], *null = pool, *root;

node *newNode() {
	static node *ptr = pool+1;
	ptr->lc = null; ptr->rc = null;
	return ptr++;
}

int n, m, op, x, y, z, rec[100005];

int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	(root = newNode())->build(1, n, rec);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op ^ 3) scanf("%d", &z);
		if (op == 1) {
			root->update2(x, y, 1, n, z);
		} else if (op == 2) {
			root->update1(x, y, 1, n, z);
		} else {
			printf("%lld\n", root->query(x, y, 1, n));
		}
	}
	return 0;
}