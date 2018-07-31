#include <bits/stdc++.h>
using namespace std;

char str[400005];
bool del[400005];
int n, k;

int main() {
	scanf("%d%d%s", &n, &k, str);
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < n; j++) {
			if (str[j] != i + 'a') continue;
			if (!k--) goto end;
			del[j] = true;
		}
	}
	end:
	for (int i = 0; i < n; i++) {
		if (!del[i]) putchar(str[i]);
	}
	return 0;
}