#include <bits/stdc++.h>
using namespace std;

long long s, rec[100005];
int n, a, b;

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", rec+i);
		s += rec[i];
	}
	sort(rec+2, rec+n+1);
	if (a * rec[1] >= s * b) {
		puts("0");
		return 0;
	}
	for (int i = n; i > 1; i--) {
		s -= rec[i];
		if (a * rec[1] >= s * b) {
			printf("%d", n + 1 - i);
			return 0;
		}
	}
	return 0;
}