#include <bits/stdc++.h>
#define l(x) for (int x = 0; x < 3; x++)
using namespace std;

const int check[8][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};

map<string, string> m;
string s, x = "^", t;

bool win() {
	for (int i = 0; i < 8; i++) {
		if (s[check[i][0]] == s[check[i][1]] && s[check[i][1]] == s[check[i][2]]) {
			return true;
		}
	}
}

int main() {
	s = "^.........^";
	//Yes, my name is tourist.
	l(a) l(b) l(c) l(d) l(e) l(f) l(g) l(h) l(i) {
		
	}
	for (int i = 0; i < 3; i++) {
		cin >> t;
		x += t;
	}
	x.push_back('^');
	cout << x << " " << m.size() << endl;
	if (!m.count(t)) {
		cout << "illegal";
	} else {
		cout << m[t];
	}
}
