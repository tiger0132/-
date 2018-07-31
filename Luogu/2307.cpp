#include <bits/stdc++.h>
using namespace std;

int par[100005], c;
bool vis[100005];

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

bool merge(int x, int y) {
	if ((x = find(x)) == (y = find(y))) return true;
	par[x] = y; c++;
	return false;
}

int x, y, m;
bool f;

int main() {
	f = true;
	while (1) {
		scanf("%d%d", &x, &y);
		if (!((~x) || (~y))) {
			return 0;
		}
		if (!(x || y)) {
			printf("%d\n", f && (c+1 == m));
			memset(par, 0, sizeof par);
			memset(vis, 0, sizeof vis);
			f = true;
			m = c = 0;
			continue;
		}
		if (!vis[x]) vis[x] = 1, m++;
		if (!vis[y]) vis[y] = 1, m++;
		if (merge(x, y)) {
			f = false;
		}
	}
}