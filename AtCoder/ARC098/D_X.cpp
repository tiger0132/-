#include <iostream>
using namespace std;
 
typedef long long ll;

ll x0r, sum, rng = 1, ans;
ll rec[200005];
ll n;

int main() {
	scanf("%d", &n); ans = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	x0r = sum = rec[1];
	for (int i = 2; i <= n; i++) {
		x0r ^= rec[i];
		sum += rec[i];
		if (x0r == sum) {
			rng++;
			continue;
		} else if (rng > 1) {
			ans += (rng * (rng - 1)) >> 1;
			sum = x0r = rec[--i];
		} else {
			x0r = sum = rec[i];
		}
		rng = 1;
	}
	ans += (rng * (rng + 1)) >> 1;
	printf("%lld", ans);
	return 0;
}