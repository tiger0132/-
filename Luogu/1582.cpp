#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

inline int lowbit(int x) {
	return x&-x;
}

int main() {
	scanf("%d%d", &n, &k);
	while (__builtin_popcount(n) > k) {
		ans += lowbit(n);
		n += lowbit(n);
	}
	printf("%d", ans);
	return 0;
}