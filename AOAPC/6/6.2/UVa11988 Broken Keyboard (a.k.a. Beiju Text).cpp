#include <bits/stdc++.h>
using namespace std;

char str[100005];
string x, ans;
int n, f;

void upd() {
	if (f == 1) ans = x + ans;
	if (f == 2) ans += x;
	x.clear();
}

void add(char c) {
	if (f) x += c;
	else ans += c;
}

int main() {
	while (~scanf("%s", str)) {
		n = strlen(str);
		ans.clear();
		x.clear();
		f = 0;
		for (int i = 0; i < n; i++) {
			if (str[i] == '[') {
				upd(); f = 1;
			} else if (str[i] == ']') {
				upd(); f = 2;
			} else {
				add(str[i]);
			}
		}
		upd();
		puts(ans.c_str());
	}
}