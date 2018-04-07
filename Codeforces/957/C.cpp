#include <bits/stdc++.h>
using namespace std;

int n, u, k, rec[100005];
int ai, aj, ak;
double loss;

int main() {
	scanf("%d%d", &n, &u);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec + i);
	}
	loss = -1;
	for (int i = 1; i < n - 1; i++) {
		int j = i + 1;
		k = max(k, i);
		while (k + 1 <= n && rec[k + 1] - rec[i] <= u) k++;
		if (k <= i + 1) continue;
		double tl = 1. * (rec[k] - rec[j]) / (rec[k] - rec[i]);
		loss = max(loss, tl);
		// printf("%d %d %d %lf\n", i, j, k, loss);
	}
	if (loss == -1) puts("-1");
	else printf("%.12lf", loss);
	return 0;
}