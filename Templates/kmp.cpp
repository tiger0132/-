#include <bits/stdc++.h>
using namespace std;

char src[1000006], pattern[1000006];
int fail[1000006];
vector<int> ans;
int n, m;

void getfail() {
	fail[0] = -1;
	int match = -1;
	for (int i = 1; i < m; i++) {
		while (match >= 0 && pattern[match + 1] != pattern[i]) {
			match = fail[match];
		}
		if (pattern[match + 1] == pattern[i]) {
			match++;
		}
		fail[i] = match;
	}
}

void kmp(vector<int>& pos) {
	getfail();
	int match = -1;
	for (int i = 0; i < n; i++) {
		while (match >= 0 && pattern[match + 1] != src[i]) {
			match = fail[match];
		}
		if (pattern[match + 1] == src[i]) {
			match++;
			if (match == m-1) {
				printf("%d\n", i - m + 1 + 1);
			}
		}
	}
}

int main() {
	scanf("%s%s", src, pattern);
	n = strlen(src);
	m = strlen(pattern);
	kmp(ans);
	for (int i = 0; i < m; i++) {
		printf("%d ", fail[i] + 1);
	}
	return 0;
}