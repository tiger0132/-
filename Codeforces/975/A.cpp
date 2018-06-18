#include <bits/stdc++.h>
using namespace std;

set<string> sset;
string s;
int n;

int main() {
	for (scanf("%d", &n); n--; ) {
		cin >> s;
		sort(s.begin(), s.end());
		s.erase(unique(s.begin(), s.end()), s.end());
		sset.insert(s);
	}
	printf("%d", sset.size());
	return 0;
}