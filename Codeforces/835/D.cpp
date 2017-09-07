#include <bits/stdc++.h>
#define NIL 0x3f3f3f3f
using namespace std;

typedef unsigned long ul;

int table[5000][5000];
ul h[5000][5000];
int ans[2500];
string s;
int n;

int judge(int l, int r) {
//	cout << "[" << l << "," << r << "]";
	if (table[l][r] != NIL) {
//		cout << table[l][r] << endl;
		return table[l][r];
	} else if (h[l][r] == h[r][l]) {
		int ret = min(judge(l, l + (r - l + 1) / 2 - 1), judge(r - (r - l + 1) / 2 + 1, r));
//		cout << max(ret + 1, 1) << endl;
		return table[l][r] = max(ret + 1, 1);
	} else {
//		cout << 0 << endl;
		return table[l][r] = 0;
	}
}

int main() {
	memset(table, 0x3f, sizeof(table));
	cin >> s;
	n = s.size(); 
	for (int i = 0; i < n; i++) {
		h[i][i] = s[i];
		for (int j = i + 1; j < n; j++) {
			h[i][j] = h[i][j - 1] * 17 + s[j];
		}
		for (int j = i - 1; j >= 0; j--) {
			h[i][j] = h[i][j + 1] * 17 + s[j];
		}
	} 
	for (int i = 0; i < n; i++) {
		table[i][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = 1; k <= judge(i, j); k++) {
				ans[k]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
} 
