#include <bits/stdc++.h>
using namespace std;

int D, I, k, n;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &D, &I);
		k = 1;
//		for (int i = 0; i < D-1; i++) {
//			if (I % 2) { k = k * 2; I = (I + 1) / 2; }
//			else { k = k * 2 + 1; I /= 2; }
//		}
		while (--D) {
			if (I & 1) {
				k <<= 1;
				I = (I + 1) >> 1;
			} else {
				k = (k << 1) | 1;
				I >>= 1;
			}
		}
		printf("%d\n", k);
	}
}