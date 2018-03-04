#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	freopen("input1001.txt", "w", stdout);
	srand((17504216006 % 20060516ll * time(0) + 998244353) % 1000000007);
	n = rand() % 10 + 1;
	m = rand() % 10 + 1;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			printf("%d ", rand() % 10 + 1);
		} puts("");
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d ", rand() % 10 + 1);
		} puts("");
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			printf("%d ", rand() % 10 + 1);
		} puts("");
	}
}