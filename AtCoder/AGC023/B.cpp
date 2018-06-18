#include <bits/stdc++.h>
using namespace std;

char rec[310][310];
int n, ans;

int sm(int x, int offset) {
	return (x + offset + n - 1) % n + 1;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", rec[i]+1);
	}
	for (int a = 0; a < n; a++) {\
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int nx = sm(i, a);
				int ny = sm(j, -a);
				if (rec[i][j] != rec[ny][nx]) goto end;
			}
		}
		// printf("%d %d\n", a, b);
		ans++;
		end:;
	}
	printf("%d", ans * n);
	return 0;
}