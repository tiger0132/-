#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	scanf("%d", &n);
	printf("%d\n", n + (n >> 1));
	for (int i = 1; i <= n; i++) if (~i&1) printf("%d ", i);
	for (int i = 1; i <= n; i++) if ( i&1) printf("%d ", i);
	for (int i = 1; i <= n; i++) if (~i&1) printf("%d ", i);
}
