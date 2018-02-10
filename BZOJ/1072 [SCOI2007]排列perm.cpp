#include <algorithm>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

int t, n, d;
char s[15];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s%d", s, &d);
		int ans = 0;
		n = strlen(s);
		for (register int i = 0; i < n; i++) s[i] ^= 48;
		sort(s, s+n);
		do {
			long long x = 0;
			for (register int i = 0; i < n; i++) x = x * 10 + s[i];
			ans += !(x % d);
		} while (next_permutation(s, s+n));
		printf("%d\n", ans);
	}
}