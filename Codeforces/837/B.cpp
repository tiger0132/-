#include <bits/stdc++.h>
using namespace std;

bool match1 = true, match2 = true;
string s[128];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = '0' + s[i];
	}
	if (n % 3 == 0) {
		int p1 = n / 3 * 1;
		int p2 = n / 3 * 2;
		char x1, x2, x3;
		x1 = s[1][1];
		x2 = s[p1 + 1][1];
		x3 = s[p2 + 1][1];
		if (x1 == x2 || x2 == x3 || x1 == x3 || !strchr("RGB", x1) || !strchr("RGB", x2) || !strchr("RGB", x3)) {
			match1 = false;
			goto end;
		}
		for (int i = 1; i <= p1; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] != x1) {
					match1 = false;
					goto end;
				}
			}
		}
		for (int i = p1 + 1; i <= p2; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] != x2) {
					match1 = false;
					goto end;
				}
			}
		}
		for (int i = p2 + 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (s[i][j] != x3) {
					match1 = false;
					goto end;
				}
			}
		}
	} else {
		match1 = false;
	}
	end:
	if (m % 3 == 0) {
		int p1 = m / 3 * 1;
		int p2 = m / 3 * 2;
		char x1, x2, x3;
		x1 = s[1][1];
		x2 = s[1][p1 + 1];
		x3 = s[1][p2 + 1];
		if (x1 == x2 || x2 == x3 || x1 == x3 || !strchr("RGB", x1) || !strchr("RGB", x2) || !strchr("RGB", x3)) {
			match2 = false;
			goto end2;
		}
		for (int i = 1; i <= p1; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[j][i] != x1) {
					match2 = false;
					goto end2;
				}
			}
		}
		for (int i = p1 + 1; i <= p2; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[j][i] != x2) {
					match2 = false;
					goto end2;
				}
			}
		}
		for (int i = p2 + 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[j][i] != x3) {
					match2 = false;
					goto end2;
				}
			}
		}
	} else {
		match2 = false;
	}
	end2:
	cout << ((match1 || match2) ? "YES" : "NO");
}
