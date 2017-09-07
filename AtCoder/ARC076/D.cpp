#include <bits/stdc++.h>
using namespace std;

pair<int, int> px[100005], py[100005];
int n, x[100005], y[100005], z;

int dist(int x1, int y1, int x2, int y2) {
	return min(abs(x1 - x2), abs(y1 - y2));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		px[i] = make_pair(x[i], i);
		py[i] = make_pair(y[i], i);
	}
	sort(px, px + n);
	sort(py, py + n);
	set<pair<int, pair<int, int>>> s;
	for (int i = 0; i < n - 1; i++) {
		s.insert(make_pair(dist(px[i], px[i + 1]), make_pair(px[i].second, px[i + 1].second)));
		s.insert(make_pair(dist(py[i], py[i + 1]), make_pair(py[i].second, py[i + 1].second)));
		
	}
}
