#include <bits/stdc++.h>
using namespace std;

#ifdef __TIGER0133__
#define lld "%lld"
#else
#define lld "%I64d"
#endif

typedef long long ll;

const double EPS = 1e-6, INF = 1e30;

struct line {
	double k, b;
	bool xmode;
	bool operator==(const line& rhs) const {
		return fabs(k - rhs.k) < EPS && fabs(b - rhs.b) < EPS && xmode == rhs.xmode;
	}
	bool operator<(const line& rhs) const {
		return fabs(b - rhs.b) < EPS ? k < rhs.k : b < rhs.b;
	}
};

struct point {
	double x, y; // (x, y)
	bool operator<(const point& rhs) const {
		return fabs(x - rhs.x) < EPS ? y < rhs.y : x < rhs.x;
	}
	bool operator==(const point& rhs) const {
		return fabs(y - rhs.x) < EPS && fabs(y - rhs.y) < EPS;
	}
} p[100005];

bool inLine(int i, int j, int k) {
	return fabs((p[k].x - p[i].x) * (p[k].x - p[j].x)
			  - (p[k].y - p[i].y) * (p[k].y - p[j].y)) < EPS;
}

line makeLine(int i, int j) {
	line ret;
	ret.xmode = fabs(p[i].x - p[j].x) > EPS;
	double _x1 = p[i].x, _y1 = p[i].y, _x2 = p[j].x, _y2 = p[j].y;
	double dx = _x1 - _x2, dy = _y1 - _y2;
	ret.k = (ret.xmode ? dy / dx : dx / dy);
	ret.b = (ret.xmode ? _y1 - ret.k * _x1 : _x1 - ret.k * _y1);
	return ret;
}

double slope(int i, int j) {
	return (p[i].y - p[j].y) / (p[i].x - p[j].x);
}

set<line> k;
int n, cnt;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	sort(p + 1, p + n + 1);
	n = unique(p + 1, p + n + 1) - p - 1;
	for (int i = 1; i <= n; i++) {
		k.clear();
		for (int j = 1; j <= n; j++) if (i != j) {
			line t = makeLine(i, j);
			k.insert(t);
			printf("%d: k = %lf, b = %lf, xmode = %s\n", i, t.k, t.b, t.xmode ? "true" : "false");
		}
		if (k.size() <= 2) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}