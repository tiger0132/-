#include <bits/stdc++.h>
using namespace std;

char c[10];
int ans;

int main() {
	while (1) {
		ans = 0;
		gets(c);
		for (int i = 0; c[i]; i++) {
			ans += c[i] - 'A';
		}
		printf("%d\n", ans);
	}
}