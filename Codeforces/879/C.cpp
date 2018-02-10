#include <bits/stdc++.h>
#define p(q) ((q) && (q) != X)
#define X 0x3f3f3f3f
using namespace std;

int a = 0, b = 1023;
char op[1];
int n, t;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s%d", op, &t);
		switch (*op) {
			case '&':
				a &= t;
				b &= t;
				break;
			case '|': 
				a |= t;
				b |= t;
				break;
			case '^':
				a ^= t;
				b ^= t;
				break;
		}
	}
	printf("2\n| %d\n^ %d", a ^ b ^ 1023, b ^ 1023);
}
