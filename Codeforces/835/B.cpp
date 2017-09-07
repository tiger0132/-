#include <bits/stdc++.h>
using namespace std;

long long k, x, ans, index;
string s;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> k >> s;
	sort(s.begin(), s.end());
	for (char i : s) {
		x += i - '0';
	}
	while (x < k) {
		x += '9' - s[index++];
		if (s[index] != 9) {
			ans++;
		}
	}
	cout << ans;
}
