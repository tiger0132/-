#include <bits/stdc++.h>
using namespace std;

struct edge {
	int from, to, w;
	bool operator<(const edge& rhs) const {
		return w < rhs.w;
	}
} e[6003];

int size[6003];
int par[6003];
long long ans;
int t, n;

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(size, 0, sizeof size);
		memset(par, 0, sizeof par);
		memset(e, 0, sizeof e);
		scanf("%d", &n);
		size[n] = 1; ans = 0;
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &e[i].from, &e[i].to, &e[i].w);
			size[i] = 1;
		}
		sort(e, e+n);
		for (int i = 1; i < n; i++) {
			int x = find(e[i].from);
			int y = find(e[i].to);
			if (x == y) continue;
			ans += (e[i].w + 1ll) * (size[x] * size[y] - 1);
			size[y] += size[x]; par[x] = y;
		}
		printf("%lld\n", ans);
	}
	return 0;
}