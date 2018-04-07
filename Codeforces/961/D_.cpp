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
		return fabs(k - rhs.k) < EPS && fabs(b - rhs.b) < EPS;
	}
	bool operator<(const line& rhs) const {
		return b < rhs.b;
	}
};

struct point {
	double x, y; // (x, y)
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
	return (p[i].y - p[j].y) / (p[i].x - p[i].y);
}

int color[100005];
map<int, line> ID;
set<line> lines;
set<double> k;
int n, cnt;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	for (int i = 1; i < n - 1; i++) {
		bool inserted = false;
		for (int j = i + 2; j <= n; j++) {
			if (inLine(i, i+1, j)) {
				if (!inserted) {
					lines.insert(makeLine(i, i+1));
					ID[++cnt] = makeLine(i, i+1);
					color[i] = color[i+1] = cnt;
				}
				color[j] = cnt;
			}
			if (cnt > 2) {
				puts("NO");
				return 0;
			}
		}
		if (cnt > 0) {
			double sl = INF;
			int first = 0;
			for (int i = 1; i <= n; i++) {
				if (!color[i]) {
					if (!first) first = i;
					else {
						double kx = slope(first, i);
						if (sl == INF) sl = kx;
						else if (fabs(sl - kx) > EPS) goto end;
					}
				}
			}
			puts("YES");
			return 0;
		}
		end:;
	}
	assert(0);
	return 0;
}