#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> book;
ll ans, t, psum;
int n;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &t);
		psum += t;
		ans += book[psum];
		book[psum]++;
	}
	printf("%lld", ans);
	return 0;
}