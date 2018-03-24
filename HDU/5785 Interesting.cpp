#include <bits/stdc++.h>
using namespace std;

char tmp[11000007], str[22000007];
int p[22000007];
int n;

int manacher() {
	int rb = 0, mid, ans = 0;
	for (int i = 1; i < n; i++) {
		if (i < rb) p[i] = min(p[2 * mid - i], p[mid] + mid - i);
		else p[i] = 1;
		while (str[i + p[i]] == str[i - p[i]]) p[i]++;
		if (p[i] + i > rb) {
			rb = p[i] + i;
			mid = i;
		} 
		ans = max(ans, p[i]);
	}
	return ans;
}

void init() {
	fread(tmp, sizeof tmp, 1, stdin);
	// gets(tmp);
	n = strlen(tmp);
	str[0] = '$'; str[1] = '|';
	for (int i = 0; i < n; i++) {
		str[2 * i + 2] = tmp[i];
		str[2 * i + 3] = '|';
	}
	n = strlen(str);
}

int main() {
	init();
	printf("%d", manacher() - 1);
}