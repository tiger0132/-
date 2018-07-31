#include <bits/stdc++.h>
#define ll x<<1
#define rr (x<<1)|1
using namespace std;

typedef long long LL;

LL ans[300005], sum[300005], la[300005], ra[300005], rec[300005];
int n, m;

void pushup(int x) {
	sum[x] = sum[ll] + sum[rr];
	la[x] = max(la[ll], sum[ll] + la[rr]);
	ra[x] = max(ra[rr], sum[rr] + ra[ll]);
	ans[x] = max(max(ans[ll], ans[rr]), ra[ll] + la[rr]);
}

void build(int x, int l, int r) {
	// printf("(%d, %d, %d)\n", x, l, r);
	if (l == r) {
		sum[x] = la[x] = ra[x] = ans[x] = rec[l];
		return;
	}
	int mid = (l+r)>>1;
	build(ll, l, mid);
	build(rr, mid+1, r);
	pushup(x);
}

void update(int i, LL k, int x, int l, int r) {
	if (l == r) {
		sum[x] = la[x] = ra[x] = ans[x] = k;
		return;
	}
	int mid = (l+r)>>1;
	if (i <= mid) update(i, k, ll, l, mid);
	else update(i, k, rr, mid+1, r);
	pushup(x);
}

void query(int L, int R, int x, int l, int r, LL& ansx, LL& fr) {
	if (L <= l && r <= R) {
        ansx = max(ansx, max(fr + la[x], ans[x]));
        fr = max(fr + sum[x], ra[x]);
        return;
    }
	int mid = (l+r)>>1;
    if (L <= mid) query(L, R, ll, l, mid, ansx, fr);
    if (mid < R) query(L, R, rr, mid+1, r, ansx, fr);
}

int op, x, y;
LL ansx, fx;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", rec+i);
	}
	build(1, 1, n);
	for (scanf("%d", &m); m--; ) { 
		scanf("%d%d%d", &op, &x, &y);
		if (op) {
			ansx = -INT_MAX;
			fx = 0;
			query(x, y, 1, 1, n, ansx, fx);
			printf("%lld\n", ansx);
		} else {
			update(x, y, 1, 1, n);
		}
	}
	return 0;
}

// fAKe Problem & Data/.