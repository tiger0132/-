#include <bits/stdc++.h>
using namespace std;

map<int, int> _;
int par[100005];
int k[100005];
int m[100005];
int p[100005];
int n, a, b;

int find(int x) {
	return par[x] == x ? x : find(par[x]);
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		_[p[i]] = i;
		par[i] = i;
	}
	for (int i = 0; i < n; i++) {
		if (_.count(a - p[i])) {
			par[find(_[a - p[i]])] = find(i);
			k[i] |= 1;
		}
		if (_.count(b - p[i])) {
			par[find(_[b - p[i]])] = find(i);
			k[i] |= 2;
		}
//		printf("%d: %d %d %d\n", i, k[i], find(a - p[i]), find(b - p[i]));
	}
	for (int i = 0; i < n; i++) {
		m[i] = 3;
	}
	for (int i = 0; i < n; i++) {
		m[find(i)] &= k[i];
	}
	for (int i = 0; i < n; i++) {
		if (!m[i]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++) {
		printf("%c ", '0' + ((~m[find(i)]) & 1)); 
	}
}
