#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;
const int N = 102;

double mat[N][N];
int n;

void gauss() {
	for (int i = 1; i <= n; i++) {
		int piv = i;
		for (int j = i; j <= n; j++) {
			if (fabs(mat[j][i]) > fabs(mat[piv][i])) {
				piv = j;
			}
		}
		if (piv != i) for (int j = 1; j <= n + 1; j++) {
			swap(mat[i][j], mat[piv][j]);
		}
		if (fabs(mat[i][i]) <= EPS) {
			puts("No Solution");
			exit(0);
		}
		for (int j = i + 1; j <= n + 1; j++) {
			mat[i][j] /= mat[i][i];
		}
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				for (int k = i + 1; k <= n + 1; k++) {
					mat[j][k] -= mat[j][i] * mat[i][k];
				}
			}
		}
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n+1; v++) {
				printf("%.6lf ", mat[u][v]);
			} puts("");
		}
		puts("");
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n + 1; j++) {
			scanf("%lf", mat[i] + j);
		}
	}
	gauss();
	for (int i = 1; i <= n; i++) {
		printf("%.2lf\n", mat[i][n + 1]);
	}
	return 0;
}