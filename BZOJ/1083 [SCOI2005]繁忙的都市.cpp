#include <bits/stdc++.h>
using namespace std;

struct node {
	int s, e, x;
} e[100005];
int par[305];
int n, m, ans;

int cmp(const node& x, const node& y) {
	return x.x < y.x;
}

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

void merge(int x, int y, int ex) {
	x = find(x), y = find(y);
	if (x != y) par[x] = y, ans = max(ans, ex); 
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &e[i].s, &e[i].e, &e[i].x);
	}
	sort(e+1, e+m+1, cmp);
	for (int i = 1; i <= m; i++) {
		merge(e[i].s, e[i].e, e[i].x);
	}
	printf("%d %d", n-1, ans);
} 

1 2 3 3 3 2

