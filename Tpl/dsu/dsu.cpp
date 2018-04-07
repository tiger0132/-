#include <bits/stdc++.h>
using namespace std;

int par[100005], dep[100005];
int n, m, u, v;
char op[9];

int find(int x) {
	if (par[x]) {
		int p = par[x];
		par[x] = find(p);
		dep[x] += dep[p];
	}
	else return x;
}

int merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		par[x] = y;
		return 1;
	}
	return 0;
}

int query(int x) {
	int ret = 0;
	while (par[x]) {
		ret += dep[x] + 1;
		x = par[x];
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s%d", op, &u);
		switch (*op) {
			case 'f': printf("%d\n", find(u)); break;
			case 'm': scanf("%d", &v); puts(merge(u, v) ? "YE5" : "N0"); break;
			case 'q': printf("%d\n", query(u));
		}
	}
	return 0;
}