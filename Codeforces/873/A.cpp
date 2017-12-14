#include <bits/stdc++.h>
using namespace std;

int n, k, x, r, a;

int main() {
	scanf("%d %d %d", &n, &k, &x);
	for(int i = 1; i <= n; i++){
		scanf("%d", &r);
		if (i >= n - k + 1) {
			r = x;
		}
		a += r;
	}
	printf("%d", a);
}