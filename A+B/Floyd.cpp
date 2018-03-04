#include <bits/stdc++.h>
using namespace std;

int gph[4][4];
int a, b;

int main() {
	scanf("%d%d", &a, &b);
	memset(gph, 63, sizeof gph);
	gph[1][2] = a;
	gph[2][3] = b;
	for (int k = 1; k <= 3; k++) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (i != j && i != k && j != k) {
					gph[i][j] = min(gph[i][j], gph[i][k] + gph[k][j]);
				}
			}
		}
	}
	printf("%d", gph[1][3]);
}