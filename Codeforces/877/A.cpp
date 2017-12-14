#include <bits/stdc++.h>
using namespace std;

const string rec[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
string a;
int x;

int main() {
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if (i + rec[j].size() <= a.size()) {
				x += (rec[j] == a.substr(i, rec[j].size()));
			}
		}
	}
	cout << (x == 1 ? "YES" : "NO");
}
