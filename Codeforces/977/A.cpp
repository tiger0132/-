#include <bits/stdc++.h>
using namespace std;

long long n;
int k;

int main() {
	scanf("%I64d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		if (n % 10) n--;
		else n /= 10;
	}
	printf("%I64d", n);
	return 0;
}