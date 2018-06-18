#include <bits/stdc++.h>
using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, cl, ce, v, q;
int x1_, y1_, x2_, y2_;
int nl[100005];
int ne[100005];
int l[100005];
int e[100005];
int pos;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
	pos = 1;
	for (int i = 1; i <= cl; i++) {
		scanf("%d", l+i);
		while (pos < l[i]) nl[++pos] = i-1;
	} while (pos <= n) nl[++pos] = cl;
	pos = 1;
	for (int i = 1; i <= ce; i++) {
		scanf("%d", e+i);
		while (pos < e[i]) ne[++pos] = i-1;
	} while (pos <= n) ne[++pos] = cl;
	for (scanf("%d", &q); q--; ) {
		scanf("%d%d%d%d", &x1_, &y1_, &x2_, &y2_);
		int c1, c2, c3, c4, c5;
		c1 = c2 = c3 = c4 = c5 = oo;
		if (nl[y1_] > 0) c1 = abs(y1_ - l[nl[y1_]]) + abs(y2_ - l[nl[y1_]]) + abs(x1_ - x2_);
		if (nl[y1_] < cl) c2 = abs(l[nl[y1_] + 1] - y1_) + abs(l[nl[y1_] + 1] - y2_) + abs(x1_ - x2_);
		if (ne[y1_] > 0) c3 = abs(y1_ - e[ne[y1_]]) + abs(y2_ - e[ne[y1_]]) + (int)ceil(1. * abs(x1_ - x2_) / v);
		if (ne[y1_] < ce) c4 = abs(e[ne[y1_] + 1] - y1_) + abs(e[ne[y1_] + 1] - y2_) + (int)ceil(1. * abs(x1_ - x2_) / v);
		if (x1_ == x2_) c5 = abs(y2_ - y1_);
		printf("%d\n", min(min(c1, c2), min(c3, min(c4, c5))));
	}
	return 0;
}