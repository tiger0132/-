#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next;
} e[400005];

int head[200005], cnt = 1;
int color[200005];
int n, m, a1, a2, a3, a4;
int deg[200005];
int cyclen;

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y]}; head[y] = cnt;
	deg[x]++; deg[y]++;
}

void dfs(int x, int p, int c) {
	color[x] = c; a1++; a2++; a3 += deg[x];
	if (a2 > cyclen && cyclen) cyclen = 0x3f3f3f3f;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to; a4++;
		if (nx == p) continue;
		if (color[nx] && !cyclen) {
			cyclen = a2;
		}
		if (!color[nx]) dfs(nx, x, c);
	} a2--;
}

int x, y, c, ans;

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			a1 = a2 = a3 = a4 = cyclen = 0;
			dfs(i, ++c, -1); // foolish proccess 2333
			if (a1 == cyclen && a1 > 2 && a3 == a1 * 2 && a4 == a3) ans++;
		}
	}
	printf("%d", ans);
	return 0;
}