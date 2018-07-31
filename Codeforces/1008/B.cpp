#include <bits/stdc++.h>
using namespace std;

int w[100005], h[100005];
int n, c;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", w+i, h+i);
	}
	c = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		int a = max(w[i], h[i]);
		int b = min(w[i], h[i]);
		if (b > c) {
			puts("NO");
			return 0;
		}
		if (a <= c) c = a;
		else if (b <= c) c = b;
	}
	puts("YES");
	return 0;
}