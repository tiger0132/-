#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxp = 100010, p = 1e9 + 7;

ll qp(ll x, ll y) {
    if (y == 0) return 1;
    ll res = qp(x, y >> 1);
    res = res * res % p;
    if (y & 1) res = res * x % p;
    return res;
}

int main() {
	printf("%lld", qp(5, 5));
	while (1);
}