#include <bits/stdc++.h>
#define optimize __attr ## ibute__ ((optimize("-O2")))
using namespace std;

int n;
int l, r, k1, k2, ans, arr[16];

double f(int x) {
	return arr[x];
}

optimize int main() {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	while (abs(l - r) > 1) {
		k1 = l + (r - l) / 3;
		k2 = l + (r - l) / 3 * 2;
		if (f(k1) >= f(k2)) {
			r = k2;
		} else {
			l = k1;
		}
	}
	printf("%d", l);
}