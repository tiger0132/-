#include <bits/stdc++.h>
using namespace std;

int a[55];
int b[55];
int n, m;

int main(int argc, char *argv[]) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", b+i);
	}
	nth_element(a+1, a+n-1, a+n+1);
	printf("%I64d", (long long)a[n-1] * (long long)*max_element(b+1, b+m+1));
} 