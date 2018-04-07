#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main() {
	srand(time(0));
	n = 2000000000;
	for (int i = 1; i <= n; i++) {
		double x = 1. * rand() / RAND_MAX * (rand() % 2 ? -1 : 1);
		double y = 1. * rand() / RAND_MAX * (rand() % 2 ? -1 : 1);
		if (x * x + y * y <= 1) cnt++;
	}
	printf("%lf", 1. * cnt / n * 4);
	return 0;
}