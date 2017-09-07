#include <bits/stdc++.h>
using namespace std;

int n, q, c, x, y, s, t, xx1, xy1, xx2, xy2;
int row[128][128][16], all[128][128][16];
int arr[128][128][16];

int main() {
	cin >> n >> q >> c;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &x, &y, &s);
		for (int j = 0; j <= c; j++) {
			arr[x][y][j] += s;
			s = (s + 1) % (c + 1);
		}
	}
	int k = 0, cnt = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 0; k <= c; k++) {
				all[i][j][k] = all[i - 1][j][k] + (row[i][j][k] = row[i][j - 1][k] + arr[i][j][k]);
			}
		}
	}
	while (q--) {
		scanf("%d%d%d%d%d", &t, &xx1, &xy1, &xx2, &xy2);
		t %= c + 1;
		printf("%d\n", all[xx2][xy2][t] + all[xx1 - 1][xy1 - 1][t] - all[xx1 - 1][xy2][t] - all[xx2][xy1 - 1][t]);
	}
}
