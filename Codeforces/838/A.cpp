#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0x3f3f3f3f;
int xx1, xy1, xx2, xy2;
int toggle[5005][5005];
char arr[5005][5005];
int all[5005][5005];
int i, j, k, N, M;

//void __SIGSEGV(int code) {
//	cout << "k = " << k << ", N = " << N << ", M = " << M << ", i = " << i << ", j = " << j << endl;
//	cout << xx1 << ", " << xy1 << ", " << xy1 << ", " << xy2 << endl;
//}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
//	signal(SIGSEGV, __SIGSEGV);
	cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> arr[i] + 1;
		for (j = 1; j <= m; j++) {
			arr[i][j] -= 48;
		}
	}
	for (i = 1; i < 5005; i++) {
		for (j = 1; j < 5005; j++) {
			all[i][j] = all[i - 1][j] + all[i][j - 1] - all[i - 1][j - 1] + arr[i][j];
		}
//		cout << endl;
	}
	for (k = 2; k <= max(n, m); k++) {
		N = n;
		M = m;
		if (n % k) N = (n / k + 1) * k;
		if (m % k) M = (m / k + 1) * k;
		int cnt = 0;
		for (i = 0; i < N / k; i++) {
			for (j = 0; j < M / k; j++) {
				int xx1 = i * k + 1;
				int xy1 = j * k + 1;
				int xx2 = (i + 1) * k;
				int xy2 = (j + 1) * k;
				int c = all[xx2][xy2] + all[xx1 - 1][xy1 - 1] - all[xx1 - 1][xy2] - all[xx2][xy1 - 1];
//				cout << c << endl;
				cnt += min(c, k * k - c);
			}
		}
//		cout << k << ": " << endl << "N = " << N << ", M = " << M << ", cnt = " << cnt << endl;
		ans = min(ans, cnt);
	}
	cout << ans;
}
