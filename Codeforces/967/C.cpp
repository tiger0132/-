#include <bits/stdc++.h>
using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, cl, ce, v, q;
int x1_, y1_, x2_, y2_;
int l[100005];
int e[100005];
int pos;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
	for (int i = 1; i <= cl; i++) {
		scanf("%d", l+i);
		// for (int j = l[i-1]; j < l[i]; j++) nl[j] = i-1;
	}
	// for (int j = l[cl]; j <= m; j++) nl[j] = cl;
	for (int i = 1; i <= ce; i++) {
		scanf("%d", e+i);
		// for (int j = e[i-1]; j < e[i]; j++) ne[j] = i-1;
	}
	// for (int j = e[ce]; j <= m; j++) ne[j] = ce;
	// for (int i = 1; i <= m; i++) {
	// 	printf("%d ", nl[i]);
	// } puts("");
	// for (int i = 1; i <= m; i++) {
	// 	printf("%d ", ne[i]);
	// } puts("");
	for (scanf("%d", &q); q--; ) {
		scanf("%d%d%d%d", &x1_, &y1_, &x2_, &y2_);
		int c1, c2, c3, c4, c5;
		c1 = c2 = c3 = c4 = c5 = oo;
		int lf = lower_bound(l+1, l+cl+1, y1_) - l - 1;
		int le = lower_bound(e+1, e+ce+1, y1_) - e - 1;
		if (lf > 0) c1 = abs(y1_ - l[lf]) + abs(y2_ - l[lf]) + abs(x1_ - x2_);
		if (lf < cl) c2 = abs(l[lf + 1] - y1_) + abs(l[lf + 1] - y2_) + abs(x1_ - x2_);
		if (le > 0) c3 = abs(y1_ - e[le]) + abs(y2_ - e[le]) + (int)ceil(1. * abs(x1_ - x2_) / v);
		if (le < ce) c4 = abs(e[le + 1] - y1_) + abs(e[le + 1] - y2_) + (int)ceil(1. * abs(x1_ - x2_) / v);
		if (x1_ == x2_) c5 = abs(y2_ - y1_);
		printf("%d\n", min(min(c1, c2), min(c3, min(c4, c5))));
	}
	return 0;
}