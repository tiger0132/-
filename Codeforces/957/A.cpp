#include <bits/stdc++.h>
using namespace std;

char last, bcount;
string s;
int n, f;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == last && s[i] != '?') {
			puts("No");
			return 0;
		}
		bcount += (s[i] == '?');
		last = s[i];
	}
	if (!bcount) {
		puts("No");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (i == 0 || i == n - 1) f = 1;
			else if (s[i - 1] == '?' || s[i + 1] == '?') f = 1;
			else if (s[i - 1] == s[i + 1]) f = 1;
		}
		if (f == 1) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}