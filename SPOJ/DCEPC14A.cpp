#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, z;
	bool operator<(const node& rhs) const {
		if (z == rhs.z) {
			if (x == rhs.x) return y > rhs.y;
			return x > rhs.x;
		}
		return z > rhs.z;
	}
} rec[100005];

int n, m, x, cnt, tree[502][502];
long long ans;

inline int lowbit(int x) {
	return x&-x;
}

void add(int x, int y, int z) {
	for (int i = x; i <= n; i += lowbit(i)) {
		for (int j = y; j <= m; j += lowbit(j)) {
			tree[i][j] += z;
		}
	}
}

long long query(int x, int y) {
	long long ret = 0;
	for (int i = x; i; i -= lowbit(i)) {
		for (int j = y; j; j -= lowbit(j)) {
			ret += tree[i][j];
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			rec[++cnt] = (node){i, j, x};
		}
	}
	sort(rec+1, rec+cnt+1);
	for (int i = 1; i <= cnt; i++) {
		ans += query(rec[i].x, rec[i].y);
		add(rec[i].x, rec[i].y, 1);
	}
	printf("%lld", ans);
	return 0;
}