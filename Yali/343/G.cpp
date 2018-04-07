#include <bits/stdc++.h>
using namespace std;

const double oo = 1e30, _oo = -1e30;

struct node {
	double x, c, d;
	bool operator < (const node& rhs) const {
		return x < rhs.x;
	}
} rec[1003];

double dp[1003][1003][2];
int vis[1003][1003][2];
int psum[1003];
int n, color;

double v, x;

double cst(double from, double to, int p, int q) {
	double fd = 0;
	if (p >= 0 && q >= 0) fd += psum[q] - psum[p - 1];
	return (psum[n] - fd) * fabs(to - from) / v;
}

double dfs(int p, int q, int k) {
	if (p == 1 && q == n) return 0;
	double& ans = dp[p][q][k];
	if (vis[p][q][k] == color) return ans;
	vis[p][q][k] = color;
	ans = oo;
	double nx = (k ? rec[q].x : rec[p].x);
	if (p > 1) ans = min(ans, dfs(p - 1, q, 0) + cst(nx, rec[p - 1].x, p, q));
	if (q < n) ans = min(ans, dfs(p, q + 1, 1) + cst(nx, rec[q + 1].x, p, q));
	return ans;
}

int main() {
	while (~scanf("%d%lf%lf", &n, &v, &x)) {
		if (!n && !v && !x) break;
		memset(psum, 0, sizeof psum);
		memset(rec, 0, sizeof rec);
		double sc = 0, ans = oo;
		color++;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf%lf", &rec[i].x, &rec[i].c, &rec[i].d);
			sc += rec[i].c;
		}
		sort(rec + 1, rec + n + 1);
		for (int i = 1; i <= n; i++) {
			psum[i] = psum[i - 1] + rec[i].d;
		}
		rec[0].x = _oo;
		rec[n + 1].x = oo;
		for (int i = 1; i <= n + 1; i++) {
			if (x > rec[i - 1].x && x < rec[i].x) {
				if (i > 1) ans = min(ans, dfs(i - 1, i - 1, 0) + cst(x, rec[i - 1].x, -1, -1));
				if (i <= n) ans = min(ans, dfs(i, i, 0) + cst(x, rec[i].x, -1, -1));
				break;
			}
		}
		printf("%.lf\n", floor(ans + sc));
	}
}