#include <bits/stdc++.h>
using namespace std;

int n, k, two[256], five[256], ans, ans2;
long long x;

int get(long long val, int f) {
	int ret = 0;
	while (val % f == 0) {
		ret++;
		val /= f;
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		two[i] = get(x, 2);
		five[i] = get(x, 5);
	}
	sort(two, two + n, greater<int>());
	sort(five, five + n, greater<int>());
	for (int i = 0; i < k; i++) {
		ans += two[i];
		ans2 += five[i];
	}
	cout << min(ans, ans2);
}
