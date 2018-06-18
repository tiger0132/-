#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>

using namespace std;

set<string> ips;
vector<string> cases;
set<string> cases2;

void work(vector<int> s, int dep) {
	if (s.size() >= 2) { //Printable
		string str;
		sort(s.begin(), s.end());
		for (int i : s) {
			str += i + '0';
		}
		cases.push_back(str); 
	}
	if (s.size() < 6) { //Expandable
		set<int> s2(s.begin(), s.end());
		for (int i : s2) {
			s.push_back(i);
			work(s, dep + 1);
			s.pop_back();
		}
	}
}

int main() {
	int arr[16], u, v;
	vector<int> s;
	cin >> u;
	if (u > 6) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < u; i++) {
		cin >> v;
		s.push_back(v);
	}
	if (u == 1 && s[0] == 0) {
		cout << "1\n0.0.0.0";
		return 0;
	}
	sort(s.begin(), s.end());
	work(s, 1);
	for (string i : cases) {
		do {
			string s = i;
			reverse(s.begin(), s.end());
			string k1 = i + s;
			string k2 = i + s.substr(1, s.size() - 1);
			cases2.insert(k1);
			cases2.insert(k2);
		} while (next_permutation(i.begin(), i.end()));
	}
	for (string x : cases2) {
		int n = x.size();
		for (int i = 0; i < 3 && i < n - 3; i++) {
			for (int j = i + 1; j <= i + 3 && j < n - 2; j++) {
				for (int k = j + 1; k <= j + 3 && k < n - 1; k++) {
					string A, B, C, D, X;
					int a, b, c, d;
					for (int m = 0; m <= i; m++) {
						A += x[m];
					}
					for (int m = i + 1; m <= j; m++) {
						B += x[m];
					}
					for (int m = j + 1; m <= k; m++) {
						C += x[m];
					}
					for (int m = k + 1; m <  n; m++) {
						D += x[m];
					}
					X = A + "." + B + "." + C + "." + D;
					sscanf(A.c_str(), "%d", &a);
					sscanf(B.c_str(), "%d", &b);
					sscanf(C.c_str(), "%d", &c);
					sscanf(D.c_str(), "%d", &d);
					if (a < 256 && b < 256 && c < 256 && d < 256 &&
						!(A.size() > 1 && A[0] == '0') &&
						!(B.size() > 1 && B[0] == '0') &&
						!(C.size() > 1 && C[0] == '0') &&
						!(D.size() > 1 && D[0] == '0') &&
						(find(s.begin(), s.end(), 0) != s.end() || (A[0] != '0' && B[0] != '0' && C[0] != '0' && D[0] != '0'))) {
						ips.insert(X);
					}
				}
			}
		}
	}
	cout << ips.size() << endl;
	for (string x : ips) {
		cout << x << endl;
	}
}
