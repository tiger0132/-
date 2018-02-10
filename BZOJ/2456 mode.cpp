#include <stdio.h>

int n, t, x, r;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (x == t) {
			r++;
		} else if (!r) {
			t = x;
			r = 1;
		} else {
			r--;
		}
	}
	printf("%d", t);
}
