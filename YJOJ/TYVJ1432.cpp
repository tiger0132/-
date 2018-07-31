#include <bits/stdc++.h>
using namespace std;

int tree[2000006];
int n;

inline int lowbit(int x) {
	return x&-x;
}

inline void add(int x, int y) {
	while (x <= n) {
		tree[x] += y;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int ans = 0;
	while (x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

inline int query(int l, int r) {
	return query(r) - query(l-1);
}

long long ans1, ans2;
int x;

int main() {
	freopen("in.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		add(x, 1);
		ans1 += (long long)query(x+1, n) * (n - x - query(x+1, n));
		ans2 += (long long)query(1, x-1) * (x - 1 - query(1, x-1));
	}
	printf("%lld %lld", ans1, ans2);
	while (1);
	return 0;
}