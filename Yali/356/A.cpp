#include <bits/stdc++.h>
using namespace std;

char str[100005];
long long ans, c;
int t, n;

int main() {
	for (scanf("%d", &t); t--; ) {
		scanf("%s", str); n = strlen(str);
		ans = c = 0;
		for (int i = n-1; i >= 0; i--) {
			if (str[i] != 'q') {
				ans += (c * (c+1)) >> 1;
				c = 0;
			} else c++;
		}
		ans += (c * (c+1)) >> 1;
		printf("%lld\n", ans);
	}
	return 0;
}