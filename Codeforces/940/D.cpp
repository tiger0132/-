#include <bits/stdc++.h>
using namespace std;

int n, t, a[100005], b[100005], l, r;
char ch;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d ", a + i);
	}
	while ((ch = getchar()) != '\n') {
		b[++t] = ch - 48;
	}
	l = -1000000000;
	r = 1000000000;
	for (int i = 5; i <= n; i++) {
		if ( b[i - 4] &&  b[i - 3] &&  b[i - 2] &&  b[i - 1] && !b[i]) {
			r = min(r, *min_element(a + i - 4, a + i + 1) - 1);
		}
		if (!b[i - 4] && !b[i - 3] && !b[i - 2] && !b[i - 1] &&  b[i]) {
			l = max(l, *max_element(a + i - 4, a + i + 1) + 1);
		}
	}
	printf("%d %d", l, r);
	assert(t == n);
}