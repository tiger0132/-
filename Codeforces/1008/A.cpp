#include <bits/stdc++.h>
using namespace std;

char str[1003];
int n;

int main() {
	scanf("%s", str);
	n = strlen(str);
	for (int i = 0; i < n; i++) {
		if (!strchr("aeiou", str[i])) {
			if (str[i] == 'n') continue;
			if (!strchr("aeiou", str[i+1]) || i+1==n) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}