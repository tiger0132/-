#include <bits/stdc++.h>
using namespace std;

int m, d, x, l, n;
int num[200005];
int st[200005];
char c;

void add(int u) {
	while (n && st[n] >= u) n--;
	st[++n] = u;
	num[n] = n;
}

int find(int u) {
	int ub = n - u;
	return l = st[upper_bound(num + 1, num + n + 1, ub) - num];
}

int main() {
	for (scanf("%d%d", &m, &d); m--; ) {
		scanf("%s%d", &c, &x);
		if (c == 'A') {
			add((l + x) % d);
		} else {
			printf("%d", find(x));
		}
	}
}