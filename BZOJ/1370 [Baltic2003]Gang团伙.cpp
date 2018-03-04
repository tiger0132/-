#include <bits/stdc++.h>
using namespace std;

int par[10003];
int src[10003];
int n, m, a, b;
char s[2];
int ans;

int find(int x) {
	return par[x] == x ? x : par[x] = find(par[x]);
}

void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= 2 * n; i++) {
		par[i] = i;
	}
	while (m--) {
		scanf("%1s%d%d", s, &a, &b);
		if (*s == 'F') {
			merge(a, b);
		} else {
			merge(n + a, b); merge(a, n + b);
		}
	}
	for (int i = 1; i <= n; i++) {
		src[find(i)] = 1;
	}
	for (int i = 1; i <= 2 * n; i++) {
		ans += src[i];
	}
	printf("%d", ans);
} 
