#include <bits/stdc++.h>
using namespace std;

int n, rec[1003][1003], src[1003][1003];
const int N = 1001;

inline int lowbit(int x) {
	return x&-x;
}

void add(int i, int j, int x) {
	while (i <= N) {
		int j_ = j;
		while (j_ <= N) {
			rec[i][j_] += x;
			j_ += lowbit(j_);
		}
		i += lowbit(i);
	}
}

int query(int x, int y) {
	int ret = 0;
	while (x) {
		int y_ = y;
		while (y_) {
			ret += rec[x][y_];
			y_ -= lowbit(y_);
		}
		x -= lowbit(x);
	}
	return ret;
}

int t, X1, Y1, X2, Y2;
char op[2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s%d%d", &op, &X1, &X2);
		X1++, X2++;
		if (*op == 'B') {
			if (!src[X1][X2]) add(X1, X2, 1);
			src[X1][X2] = 1;
		} else if (*op == 'D') {
			if (src[X1][X2]) add(X1, X2, -1);
			src[X1][X2] = 0;
		} else {
			scanf("%d%d", &Y1, &Y2);
			Y1++; Y2++;
			int n1 = min(X1, X2), m1 = min(Y1, Y2), n2 = max(X1, X2), m2 = max(Y1, Y2);
            printf("%d\n", query(n2, m2) - query(n1 - 1, m2) - query(n2, m1 - 1) + query(n1 - 1, m1 - 1));
		}
	}
	return 0;
}