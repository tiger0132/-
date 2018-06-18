#include <bits/stdc++.h>
using namespace std;

long long arr[21], t[21], lans, ans, tmp;

int main() {
	for (int i = 0; i < 14; i++) {
		scanf("%I64d", arr+i);
	}
	for (int i = 0; i < 14; i++) {
		memcpy(t, arr, sizeof t);
		lans = 0; tmp = t[i]; t[i] = 0;
		for (int j = 0; j < 14; j++) {
			t[j] += tmp / 14 + ((j + 14 - i) % 14 <= tmp % 14 && (j + 14 - i) % 14);
			if (t[j] % 2 == 0) lans += t[j];
		}
		ans = max(ans, lans);
	}
	printf("%I64d", ans);
	return 0;
}