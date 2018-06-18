#include <bits/stdc++.h>
using namespace std;

int T, W;

int solve(int &x) {
	int w1, d1, w2, d2;
	int b1 = 1, b2 = 1;
	scanf("%d%d%d%d", &w1, &d1, &w2, &d2);
	if (!w1) b1 = solve(w1);
	if (!w2) b2 = solve(w2);
	x = w1 + w2;
	return b1 && b2 && (w1 * d1 == w2 * d2);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		if (solve(W)) puts("YES");
		else puts("NO");
		if (T) puts("");
	}
}