#include <bits/stdc++.h>
using namespace std;

double dfs(double x, double y, int n) {
	double ret = 17041605.16;
	if (n == 1) return max(x, y) / min(x, y);
	for (int i = 1; i < n; i++) ret = min(ret, max(dfs(x, y * i / n, i), dfs(x, y * (n-i) / n, n-i)));
	for (int i = 1; i < n; i++) ret = min(ret, max(dfs(x * i / n, y, i), dfs(x * (n-i) / n, y, n-i)));
	return ret;
}

int main() {
	int x, y, n;
	scanf("%d%d%d", &x, &y, &n);
	printf("%.6f", dfs(x, y, n));
}