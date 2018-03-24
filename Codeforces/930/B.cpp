#include <bits/stdc++.h>
using namespace std;

int cnt[26][26][5003];
char str[5003];
int ans, n;

int main() {
	gets(str);
	n = strlen(str);
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < i+n; j++) {
			cnt[str[i] - 97][str[j % n] - 97][j - i + 1]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		int b = 0;
		for (int j = 1; j <= n; j++) {
			int t = 0;
			for (int k = 0; k < 26; k++) {
				t += (cnt[i][k][j] == 1);
			}
			b = max(b, t);
		}
		ans += b;
	}
	printf("%.14f", 1.*ans/n);
	return 0;
}