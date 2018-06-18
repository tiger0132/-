#include <bits/stdc++.h>
using namespace std;

const int size = 128;

int fav[size], index[size];
int connect[size][size];
int n, x;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		index[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> fav[i];
		if (i - fav[i] >= 1) {
			connect[i][i - fav[i]] = connect[i - fav[i]][i] = 1;
		}
		if (i + fav[i] <= n) {
			connect[i][i + fav[i]] = connect[i + fav[i]][i] = 1;
		}
		connect[i][i] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				connect[i][j] |= connect[i][k] && connect[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!connect[i][index[i]]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
} 
