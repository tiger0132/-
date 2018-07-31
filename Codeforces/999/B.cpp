#include <bits/stdc++.h>
using namespace std;

char str[202];
int n;

int main() {
	scanf("%d%s", &n, str);
	for (int i = 1; i <= n; i++) {
		if (n % i) continue;
		reverse(str, str+i);
	}
	puts(str);
	return 0;
}