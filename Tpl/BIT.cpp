#include <bits/stdc++.h>

int n, m, op, u, v;
int rec[500005];
int inp[500005];

inline int lowbit(int x) {
	return x&-x;
}

void add(int i, int x) {
	for (; i <= n; i += lowbit(i)) rec[i] += x;
}

int query(int i) {
	int ret = 0;
	for (; i; i -= lowbit(i)) ret += rec[i];
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
		add(i, inp[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &op, &u, &v);
		if (op == 1) {
			add(u, v);
		} else {
			printf("%d\n", query(v) - query(u - 1));
		}
	}
}