#include <bits/stdc++.h>
using namespace std;

int n, cnt, ans;
string s;

int main() {
	cin >> n;
	getchar();
	getline(cin, s);
	s.resize(n);
	for (char i : s) {
		if (i == ' ') {
			ans = max(ans, cnt);
			cnt = 0;
		} else if (i >= 'A' && i <= 'Z') {
			cnt++;
		}
	}
	cout << max(ans, cnt);
}
