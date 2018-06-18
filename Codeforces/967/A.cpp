#include <bits/stdc++.h>
using namespace std;

int n, s, x, y, l, c;

int main() {
	scanf("%d%d", &n, &s);
	l = -s - 1;
	while (n--) {
		scanf("%d%d", &x, &y);
		c = 60 * x + y;
		if (c - l - 2 >= 2 * s) {
			printf("%d %d", (l + s + 1) / 60, (l + s + 1) % 60);
			return 0;
		}
		l = c;
	}
	printf("%d %d", (c + s + 1) / 60, (c + s + 1) % 60);
	return 0;
}