#include <bits/stdc++.h>
using namespace std;

int m, n = -1, d, t = 0;
const int M = 262144;
int tree[524289];
int arr[524289];
char op[1];
int er;

int maxe(int *xarr, int x1, int x2) {
	return xarr[tree[x1]] >= xarr[tree[x2]] ? x1 : x2;
}

int max(int *xarr, int x1, int x2) {
	return xarr[tree[x1]] > xarr[tree[x2]] ? x1 : x2;
}

void add(int x) {
	int i = M + ++n;
	arr[n] = (arr[t] + x) % d;
	tree[i] = n;
	while (i >>= 1) {
		tree[i] = max(arr, i<<1, (i<<1)|1);
	}
}

int query(int l, int r) {
	int ans = -1;
	for (l += M-1, r += M+1; l ^ r ^ 1; l >>= 1, r >>= 1) {
		if (~l&1) ans = max(arr, l ^ 1, ans);
		if ( r&1) ans = max(arr, r ^ 1, ans);
	}
	return t = tree[ans];
}

void debug() {
	puts("=============================================="); 
	puts("Tree:");
	for (int i = M + 0; i <= M + n; i++) {
		printf("%d ", tree[i]);
	}
	puts("\nArr:");
	for (int i = 0; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\nt = %d", t);
	puts("\n=============================================="); 
}

int main() {
	scanf("%d%d", &m, &d);
	tree[-1] = 524288;
	for (int i = M-1; i > 0; i--) {
		tree[i] = max(arr, i<<1, (i<<1)|1);
	}
	while (m--) {
		scanf("%s%d", op, &er);
		if (*op == 'A') {
			add(er);
	debug();
		} else {
			printf("%d\n", arr[query(n - er + 1, n)]);
		}
	}
	debug();
}
