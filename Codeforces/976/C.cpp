#include <bits/stdc++.h>
using namespace std;

struct node {
	int l, r, id;
	bool operator<(const node& rhs) const {
		if (l == rhs.l) return r > rhs.r;
		return l < rhs.l;
	}
} rec[300005];

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &rec[i].l, &rec[i].r);
		rec[i].id = i;
	}
	sort(rec+1, rec+n+1);
	for (int i = 1; i < n; i++) {
		if (rec[i].l <= rec[i+1].l && rec[i+1].r <= rec[i].r) {
			printf("%d %d", rec[i+1].id, rec[i].id);
			return 0;
		}
	}
	puts("-1 -1");
	return 0;
}