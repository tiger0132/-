#include <bits/stdc++.h>
using namespace std;

int s, v1, v2, t1, t2, x1, x2;

int main() {
	cin >> s >> v1 >> v2 >> t1 >> t2;
	x1 = s * v1 + (t1 << 1);
	x2 = s * v2 + (t2 << 1);
	if (x1 < x2) {
		cout << "First";
	} else if (x2 < x1) {
		cout << "Second";
	} else {
		cout << "Friendship";
	}
}
