#include <bits/stdc++.h>
using namespace std;

int n, rec[200005], tree[200005];
vector<int> lst[200005];
long long ans;

inline lowbit(int x) {
	return x&-x;
}

void add(int i, int x) {
	while (i <= n) {
		tree[i] += x;
		i += lowbit(i);
	}
}

int query(int x) {
	int ret = 0;
	while (x) {
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
		if (rec[i] <= n) lst[rec[i]].push_back(i);
		add(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		ans += query(min(rec[i], n)) - (i <= rec[i]);
		for (int j = 0; j < lst[i].size(); j++) {
			add(lst[i][j], -1);
		}
	}
	printf("%I64d", ans >> 1);
	return 0;
}