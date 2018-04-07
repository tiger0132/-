#include <bits/stdc++.h>
using namespace std;

multiset<int>::const_iterator it, l, r;
multiset<int> ordered;
int n, t, ans;

int main() {
	scanf("%d", &n);
	ordered.insert(0x3f3f3f3f);
	ordered.insert(0xcfcfcfcf);
	while (n--) {
		scanf("%d", &t);
		it = ordered.insert(t);
		l = r = it;
		l--; r++;
		ans += (ordered.size() == 3 ? t : min(t - *l, *r - t));
	}
	printf("%d", ans);
}