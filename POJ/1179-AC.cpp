#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int n, a[122], maxx[122][122], minx[122][122];
char b [122];

int main() {
	memset(maxx, 0xcf, sizeof maxx);
	memset(minx, 0x3f, sizeof minx);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		getchar();
		scanf("%c%d", b+i, a+i);
		b[i + n] = b[i];
		a[i + n] = a[i];
	}
	for (int i = 1; i <= 2 * n; i++) {
		minx[i][i] = maxx[i][i] = a[i]; 
	}
	for (int j = 2; j <= n;j++) {
		for (int k = 1; j + k - 1 <= 2 * n; k++) {
			for (int l = k + 1; l <= j + k - 1; l++) {
				int r = j + k - 1;
				if (b[l] == 't') {
					maxx[k][r] = max(maxx[k][r], maxx[k][l-1] + maxx[l][r]);
					minx[k][r] = min(minx[k][r], minx[k][l-1] + minx[l][r]);
				} else {
					maxx[k][r] = max(maxx[k][r], maxx[k][l-1] * maxx[l][r]);
					maxx[k][r] = max(maxx[k][r], minx[k][l-1] * minx[l][r]);
					minx[k][r] = min(minx[k][r], minx[k][l-1] * minx[l][r]);
					minx[k][r] = min(minx[k][r], minx[k][l-1] * maxx[l][r]);
					minx[k][r] = min(minx[k][r], maxx[k][l-1] * minx[l][r]);
				}
			}
		}
	}
	int ans = 0xcfcfcfcf;	
	for (int i = 1; i <= n; i++)
	ans = max(ans, maxx[i][i+n-1]);	
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		if (maxx[i][i+n-1] == ans) {
			printf("%d ",i);
		}
	}
	return 0;
}