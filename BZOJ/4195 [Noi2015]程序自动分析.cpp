#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
} rec[1000006];

int t, n, c, c2, u, v, w;
int par[1000006];
map<int, int> d;

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y;
}

int id(int x) {
	if (d.count(x)) return d[x];
	return d[x] = ++c;
}

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(par, 0, sizeof par);
		memset(rec, 0, sizeof rec);
		c = c2 = 0; d.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &u, &v, &w);
			u = id(u); v = id(v);
			if (w) merge(u, v);
			else rec[++c2] = (node){u, v};
		}
		for (int i = 1; i <= c2; i++) {
			if (find(rec[i].x) == find(rec[i].y)) {
				puts("NO");
				goto end;
			}
		}
		puts("YES");
		end:;
	}
}