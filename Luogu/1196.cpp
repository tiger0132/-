#include <bits/stdc++.h>
using namespace std;

int cnt[30004], par[30004], dis[30004];

int find(int x) {
	if (par[x]) {
    	int root = find(par[x]);
    	dis[x] += dis[par[x]];
		cnt[x] = cnt[par[x]];
    	return par[x] = root;
	}
	return x;
}

void merge(int x, int y) {
    if ((x = find(x)) != (y = find(y))) {
		dis[x] = dis[y] + cnt[y];
        cnt[y] += cnt[x];
        cnt[x] = cnt[y];
        par[x] = y;
    }
}

int t, x, y;
char op[2];

int main() {
	for (int i = 1; i <= 30000; i++) {
		cnt[i] = 1;
	}
	for (scanf("%d", &t); t--; ) {
		scanf("%s%d%d", op, &x, &y);
		if (*op == 'M') {
			merge(x, y);
		} else {
			if (find(x) != find(y)) puts("-1");
			else printf("%d\n", abs(dis[x] - dis[y]) - 1);
		}
	}
	return 0;
}