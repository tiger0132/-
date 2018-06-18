#include <bits/stdc++.h>
using namespace std;

int in[10004], post[10004], lc[10004], rc[10004];
int n, ai, ax;

int build(int l1, int r1, int l2, int r2) {
	if (l1 > r1) return 0;
	int root = post[r2];
	int ptr = l1;
	while (in[ptr] != root) ptr++;
	int lcnt = ptr - l1;
	lc[root] = build(l1, ptr - 1, l2, l2 + lcnt - 1);
	rc[root] = build(ptr + 1, r1, l2 + lcnt, r2 - 1);
	return root;
}

void dfs(int cur, int sum) {
	sum += cur;
	if (!lc[cur] && !rc[cur] && (sum < ax || (sum == ax && cur < ai))) {
		ax = sum;
		ai = cur;
	}
	if (lc[cur]) dfs(lc[cur], sum);
	if (rc[cur]) dfs(rc[cur], sum);
}

bool read(int *a) {
    string line;
    if (!getline(cin, line)) {
		return false;
	}
	stringstream ss(line);
	n = 0;
	int x;
	while(ss >> x) a[n++] = x;
	return n > 0;
}

int main() {
	while (read(in)) {
		read(post);
		build(0, n-1, 0, n-1); 
		ax = 1000000000;
		dfs(post[n-1], 0);
		printf("%d\n", ai);
	}
}