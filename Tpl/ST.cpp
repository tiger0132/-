#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q, x, y;
int st[N][32];
int src[N];

void init() {
	for (int i = 1; i <= n; i++) {
		st[i][0] = src[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			st[i][j] = max(st[i][j - 1], st[i + ((1 << (j - 1)))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);  
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		scanf("%d", src + i);
	}
	init();
	while (q--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}
}