#include <bits/stdc++.h>
using namespace std;

int a[5003];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
	}
	for (int i = 1; i <= n; i++) {
		if (a[a[a[i]]] == i) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}