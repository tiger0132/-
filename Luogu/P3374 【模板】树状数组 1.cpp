#include <bits/stdc++.h>
using namespace std;

int n, m, rec[500005];

inline int lowbit(int x) {
	return x&-x;
}

int add(int i, int x) {
	while (i <= n) {
		rec[i] += x;
		i += lowbit(i);
	}
}

int query(int x) {
	int ret = 0;
	while (x) {
		ret += rec[x];
		x -= lowbit(x);
	}
	return ret;
}

int t, op, x, y;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		add(i, t);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			add(x, y);
		} else {
			printf("%d\n", query(y) - query(x - 1));
		} 
	}
	return 0;
}