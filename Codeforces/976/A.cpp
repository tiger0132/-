#include <bits/stdc++.h>
using namespace std;

char rec[202];
int n, zc, oc;

int main() {
	scanf("%d%s", &n, rec);
	n = strlen(rec);
	for (int i = 0; i < n; i++) {
		zc += (rec[i] == '0');
		oc += (rec[i] == '1');
	}
	if (n == 1) {
		puts(rec);
		return 0;
	}
	putchar(49);
	while (zc--) {
		putchar(48);
	}
	return 0;
}