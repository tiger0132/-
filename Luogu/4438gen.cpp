#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("a.in", "w", stdout);
	puts("20000");
	for (int i = 2; i < 20000; i++) {
		printf("%d -%d\n", i, i);
	}
	puts("-1 -20000");
	for (int i = 1; i <= 20000; i++) {
		puts("1 60 1");
	}
}