#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int size;

struct query {
	ll *a, *b;
	int l, r;
	bool operator<(const query& rhs) const {
		if (l / size == rhs.l / size) return r < rhs.r;
		return l < rhs.l;
	}
} q[50004];

int cnt[50004];
int rec[50004];
int n, m, l, r;
ll a[50004];
ll b[50004];
ll lans;

void update(int x, int y) {
	lans -= cnt[x] * cnt[x];
	cnt[x] += y;
	lans += cnt[x] * cnt[x];
}

int main() {
	scanf("%d%d", &n, &m);
	size = ceil(sqrt(n));
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].a = a+i;
		q[i].b = b+i;
	}
	sort(q+1, q+m+1);
	l = 1; r = 0;
	for (int i = 1; i <= m; i++) {
		if (q[i].l == q[i].r) {
			*q[i].a = 0;
			*q[i].b = 1;
			continue;
		}
		while (r < q[i].r) update(rec[++r], 1);
		while (r > q[i].r) update(rec[r--], -1);
		while (l < q[i].l) update(rec[l++], -1);
		while (l > q[i].l) update(rec[--l], 1);
		*q[i].a = lans + q[i].l - q[i].r - 1;
		*q[i].b = 1ll * (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
		ll t = __gcd(*q[i].a, *q[i].b);
		*q[i].a /= t;
		*q[i].b /= t;
	}
	for (int i = 1; i <= m; i++) {
		printf("%lld/%lld\n", a[i], b[i]);
	}
	return 0;
}