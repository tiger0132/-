#include <bits/stdc++.h>
using namespace std;

int neigh[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int best, m, n;
int a[50][50];

void search(int x) {
	int i, j, k, b1, x1, y1, xx, yy, x2, y2;
	vector<pair<int, int> > tmp;
	b1 = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				b1 = 1;
				break;
			}
		}
		if (b1 == 1) {
			break;
		}
	}
	if (b1 == 0) {
		best = x;
		return;
	}
	if (x + 1 >= best) {
		return;
	}
	xx = i;
	yy = j;
	for (k = 0; k < 5; k++) {
		x2 = xx + neigh[k][0];
		y2 = yy + neigh[k][1];
		if ((x2 >= 0) && (x2 < m) && (y2 >= 0) && (y2 < n)) {
			tmp.clear();
			for (i = 0; i < 5; i++) {
				x1 = x2 + neigh[i][0];
				y1 = y2 + neigh[i][1];
				if ((x1 >= 0) && (x1 < m) && (y1 >= 0) && (y1 < n) && (a[x1][y1] == 0)) {
					tmp.push_back(make_pair(x1, y1));
					a[x1][y1] = 1;
				}
			}
			search(x + 1);
			for (i = 0; i < tmp.size(); i++) {
				a[tmp[i].first][tmp[i].second] = 0;
			}
		}
	}
} 

int main() {
	scanf("%d%d", &m, &n);
	memset(a, 0, sizeof(a));
	best = m * n;
	search(0);
	printf("%d\n", m * n - best);
	return 0;
}
