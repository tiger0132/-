#include <bits/stdc++.h>
using namespace std;

int x = 1, a = 1, b = 0;

int main() {
	puts("1");
	for (int i = 1; i <= 10; i++) {
		printf("%d\n", x += a += b += 6);
	}
	getchar();
}