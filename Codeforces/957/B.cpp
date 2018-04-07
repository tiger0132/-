#include <bits/stdc++.h>
using namespace std;

char rec[233][233];
int n, m;

int main() {
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		gets(rec[i] + 1);
	}
	// x-axis
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// y-axis
			if (i != j) for (int p = 1; p <= m; p++) {
				for (int q = 1; q <= m; q++) {
					if (p == q) continue;

					int count = 0;
					if (rec[i][p] == '#') count++;
					if (rec[i][q] == '#') count++;
					if (rec[j][p] == '#') count++;
					if (rec[j][q] == '#') count++;
					if (count == 3) {
						puts("No");
						return 0;
					}
				}
			}
		}
	}
	puts("Yes");
	return 0;
}