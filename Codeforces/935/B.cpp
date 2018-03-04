#include <bits/stdc++.h>
using namespace std;

int rx, ry, x, y, ans;
char ch;
int n;
int f;

int main() {
	scanf("%d\n", &n);
	while ((ch = getchar()) != '\n') {
		// printf("%d %d %d %d\n", x, y, rx, ry);
		int nx = x, ny = y;
		if (ch == 'U') ny++;
		else nx++;
		if (f) {
			if ((rx < ry && nx > ny) || (rx > ry && nx < ny)) ans++;
			f = 0;
		}
		x = nx; y = ny;
		if (nx == ny) {
			f = 1;
		} else {
			rx = x; ry = y;
		}
	}
	printf("%d", ans);
}