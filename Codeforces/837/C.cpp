#include <bits/stdc++.h>
using namespace std;

int n, a, b, x[128], y[128], ans;

bool judge(int x1, int y1, int x2, int y2) {
	return   (x1 <= a && x2 <= a && y1 <= b && y2 <= b) &&
			((x1 + x1 <= a && y1 + y2 <= b) ||
			 (x1 + x2 >  a && y1 + y2 <= b) ||
			 (x1 + x2 <= a && y1 + y2 >  b));
}

int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool p = judge(x[i], y[i], x[j], y[j]);
			bool q = judge(x[i], y[i], y[j], x[j]);
			bool r = judge(y[i], x[i], x[j], y[j]);
			bool s = judge(y[i], x[i], y[j], x[j]);
			if (p || q || r || s) {
				ans = max(ans, x[i] * y[i] + x[j] * y[j]);
			}
		}
	}
	cout << ans;
}
