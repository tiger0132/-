#include <bits/stdc++.h>
using namespace std;

map<string, int> cnt;
string s, r;
int n, t;

int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = 0; i < n-1; i++) {
		string x;
		x += s[i];
		x += s[i+1];
		cnt[x]++;
	}
	for (const auto& i : cnt) {
		if (i.second > t) {
			t = i.second;
			r = i.first;
		}
	}
	cout << r;
	return 0;
}