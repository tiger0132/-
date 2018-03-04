#include <bits/stdc++.h>
using namespace std;

string out;
char src[102];
int n;

int f;

int iv(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
	scanf("%d%s", &n, src+1);
	for (int i = 1; i <= n; i++) {
		if (iv(src[i])) {
			if (!f) out += src[i];
			f = 1;
		} else {
			out += src[i];
			f = 0;
		}
	}
	puts(out.c_str());
}