#include <bits/stdc++.h>
using namespace std;

int n, m, rec[3003][3003][4];

inline int lowbit(int x) {
	return x&-x;
}

void add(int i, int j, int x) {
	int i_ = i;
	while (i_ <= n) {
		int j_ = j;
		while (j_ <= m) {
			rec[i_][j_][0] += x;
			rec[i_][j_][1] += x * i;
			rec[i_][j_][2] += x * j;
			rec[i_][j_][3] += x * i * j;
			j_ += lowbit(j_);
		}
		i_ += lowbit(i_);
	}
}

int query(int x, int y) {
	int ret = 0, x_ = x;
	while (x_) {
		int y_ = y;
		while (y_) {
			ret += (x+1) * (y+1) * rec[x_][y_][0] -
				   (y+1) * rec[x_][y_][1] -
				   (x+1) * rec[x_][y_][2] +
				   rec[x_][y_][3];
			y_ -= lowbit(y_);
		}
		x_ -= lowbit(x_);
	}
	return ret;
}

int X1, Y1, X2, Y2, delta;
char op[2];

int main() {
	scanf("X%d%d", &n, &m);
	while (~scanf("%s%d%d%d%d", op, &X1, &Y1, &X2, &Y2)) {
		if (*op == 'L') {
			scanf("%d", &delta);
			add(X1, Y1, delta);
			add(X2+1, Y1, -delta);
			add(X1, Y2+1, -delta);
			add(X2+1, Y2+1, delta);
		} else {
			printf("%d\n", query(X2, Y2) - query(X2, Y1-1) - query(X1-1, Y2) + query(X1-1, Y1-1));
		}
	}
	return 0;
}