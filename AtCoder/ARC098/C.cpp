#include <bits/stdc++.h>
using namespace std;

int n, le, lw, re, rw, ans = 0x3f3f3f3f;
char rec[300005];

int main() {
	scanf("%d%s", &n, rec+1);
	for (int i = 1; i <= n; i++) {
		(rec[i] == 'E' ? re : rw)++;
	}
	for (int i = 1; i <= n; i++) {
		(rec[i] == 'E' ? re : rw)--;
		ans = min(ans, lw + re);
		(rec[i] == 'E' ? le : lw)++;
	}
	printf("%d", ans);
	return 0;
}