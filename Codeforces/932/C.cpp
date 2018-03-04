#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int sa, sb;
int ax;

void loop(int l, int r) {
	for (int i = l; i < r; i++) {
		printf("%d ", i+1);
	} printf("%d ", l);
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i <= n / a; i++) {
		if ((n - a * i) % b == 0) {
			sa = i;
			sb = (n - a * i) / b;
		}
	}
	if (!sa && !sb) {
		puts("-1");
		return 0;
	}
	ax = sa * a;
	for (int i = 0; i < ax; i += a) {
		loop(i + 1, i + a);
	}
	for (int i = ax; i < n; i += b) {
		loop(i + 1, i + b);
	}
}