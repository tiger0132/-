#include <bits/stdc++.h>
using namespace std;

struct node {
	int to, next;
} e[400005];

int n, m, k, cnt;
int head[400005];
int par[400005];
int cra[400005];
int exi[400005];
int out[400005];
int seq[400005];
int rem;

void ins(int u, int v) {
	cnt++; e[cnt].to = v; e[cnt].next = head[u]; head[u] = cnt;
	cnt++; e[cnt].to = u; e[cnt].next = head[v]; head[v] = cnt;
}

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void add(int x) {
	int i = head[x], p = find(x), q;
	while (i) {
		if (exi[e[i].to]) {
			q = find(e[i].to);
			if (p != q) {
				par[q] = p;
				rem--;
			}
		}
		i = e[i].next;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		ins(x, y);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", seq+i);
		cra[seq[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (!cra[i]) {
			rem++;
			add(i);
			exi[i] = 1;
		}
	}
	out[k] = rem;
	for (int i = k-1; i+1; i--) {
		rem++;
		add(seq[i]);
		exi[seq[i]] = 1;
		out[i] = rem;
	}
	for (int i = 0; i <= k; i++) {
		printf("%d\n", out[i]);
	}
} 
