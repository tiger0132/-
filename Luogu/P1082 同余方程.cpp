#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) { x = 1; y = 0; return; }
	exgcd(b, a % b, y, x);
	y -= (a / b) * x;
}

ll a, b, x, y;

int main() {
	scanf("%lld%lld", &a, &b);
	exgcd(a, b, x, y);
	printf("%lld", (x + b) % b);
	return 0;
}