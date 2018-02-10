#include <bits/stdc++.h>
using namespace std;

int n, x;

int f(int x) {
	if (!x) return 0;
	if (x < 4 || x == 5 || x == 7 || x == 11) return -1;
	if (x & 1) return f(x-9) + 1;
	if (x & 2) return f(x-6) + 1;
	return x>>2;
}

int main() {
	for (scanf("%d", &n); n--; ) {
		scanf("%d", &x);
		printf("%d\n", f(x));
	}
} 
