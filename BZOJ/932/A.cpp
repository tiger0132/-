#include <bits/stdc++.h>
using namespace std;

string a;
string b;

int main() {
	cin >> a;
	b = a;
	reverse(b.begin(), b.end());
	cout << a << b;
}