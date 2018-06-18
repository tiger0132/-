#include <bits/stdc++.h>
using namespace std;

int n, k, ans, op, x, y;
int par[150005];

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

inline void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d%d", &op, &x, &y);
		if ((op == 2 && x == y) || x > n || y > n) {
			ans++;
			continue;
		}
		if (op == 1) {
			if (find(x) == find(n + y) || find(x + n) == find(y)) {
				ans++;
				continue;
			}
			merge(x, y);
			merge(x + n, y + n);
			merge(x + 2*n, y + 2*n);
		}
		if (op == 2) {
			if (find(x) == find(y) || find(x + n) == find(y)) {
				ans++;
				continue;
			}
			merge(x, y + n);
			merge(x + n, y + 2*n);
			merge(x + 2*n, y);
		}
	}
	printf("%d", ans);
	return 0;
}