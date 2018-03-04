// mmp为什么只有C++14及以上可以通过编译?详见下一篇底层博客————坑爹的编译器。

#include <bits/stdc++.h>
#ifdef LOCAL
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;

typedef long long ll;
typedef long double ld;

int q, l, n, op, ptr;
ll arr[500005];
ld ans;

ld f(ll x, int i) {
	return (x * i - arr[i]) / ld(i + 1);
}

int main() {
	scanf("%d", &q);
	ll x;
	while (q--) {
		scanf("%d", &op);
		if (op & 1) {
			scanf(lld, &x);
			while (ptr < n && f(x, ptr) <= f(x, ptr + 1)) ptr++;
			ans = max(ans, f(x, ptr));
			arr[n+1] = arr[n] + x; n++;
		} else {
			printf("%.10Lf\n", ans);
		}
	}
	#ifdef LOCAL
	getchar();
	getchar();
	#endif
}