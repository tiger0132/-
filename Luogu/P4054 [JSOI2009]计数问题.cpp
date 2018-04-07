#include <bits/stdc++.h>
using namespace std;

int rec[302][302][102], src[302][302];
int n, m;

inline int lowbit(int x) {
	return x&-x;
}

void add(int x, int y, int z, int w) {
	while (x <= n) {
		int y_ = y;
		while (y_ <= m) {
			rec[x][y_][z] += w;
			y_ += lowbit(y_);
		}
		x += lowbit(x);
	}
}

int query(int x, int y, int z) {
	int ret = 0;
	while (x) {
		int y_ = y;
		while (y_) {
			ret += rec[x][y_][z];
			y_ -= lowbit(y_);
		}
		x -= lowbit(x);
	}
	return ret;
}

int op, c, q, X1, Y1, X2, Y2;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", src[i] + j);
			add(i, j, src[i][j], 1);
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d%d%d", &X1, &Y1, &c);
			add(X1, Y1, src[X1][Y1], -1);
			add(X1, Y1, src[X1][Y1] = c, 1);
		} else {
			scanf("%d%d%d%d%d", &X1, &X2, &Y1, &Y2, &c);
			printf("%d\n", query(X2, Y2, c) - query(X1 - 1, Y2, c) - query(X2, Y1 - 1, c) + query(X1 - 1, Y1 - 1, c));
		}
	}
	return 0;
}