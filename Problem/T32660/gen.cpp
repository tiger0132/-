#include <bits/stdc++.h>
using namespace std;

const int c_n[] = {100, 200, 495, 498, 500};
const int c_m[] = {200, 300, 500, 498, 500};

char buf[1024];

int rnd() {
	return ((rand()&1) ? -1 : 1) * (rand() + 1) * rand();
}

int main() {
	for (int i = 0; i < 5; i++) {
		sprintf(buf, "predict%d.in", i);
		freopen(buf, "w", stdout);
		int n = c_n[i], m = c_m[i];
		printf("%d %d\n%d", n, m, rnd());
		for (int j = 1; j < n; j++) {
			printf(" %d", rnd());
		}
	}
}