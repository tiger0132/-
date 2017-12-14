#include <bits/stdc++.h>
using namespace std;

int num[10005] = {0, 1}, len = 1;

int n, m, k;

void mul_eq(int x) {
	int nxt = 0;
	for (int i = 1; i <= len; i++) {
		num[i] = num[i] * x + nxt;
		nxt = num[i] / 10;
		num[i] %= 10;
	}
	while (nxt) {
		num[++len] = nxt % 10;
		nxt /= 10;
	}
}

void put() {
	for (int i = len; i; i--) {
		printf("%d", num[i]);
	}
	puts("");
}

int main() {
	scanf("%d", &n); k = -n;
	if (n < 5) {
		printf("%d\n%d", n, n);
		return 0;
	}
	for (m = 2; k < 0; m++) k += m;
	for (int i = 2; i < m; i++) {
		if (i != k) {
			printf("%d ", i);
			mul_eq(i);
		}
	}
	puts("");
	put();
}
