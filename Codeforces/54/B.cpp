#include <bits/stdc++.h>
using namespace std; 

const int size = 100000007;

bool table[size];
char arr[32][32];
set<string> vec;
int a, b;

string rotate(int x1, int y1, int x2, int y2) {
	int p = x2 - x1, q = y2 - y1;
	string a, b;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			ret += arr[i][j];
			b = arr[p - i - 1][q - j - 1];
		}
	}
	a = min(a, b);
	if (a != b) {
		for (int i = x2 - 1; i >= x1) {
			
		}
	}
	
} 

int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < a; i++) {
		if (a % i == 0) {
			for (int j = 0; j < b; j++) {
				if (b % j == 0) {
					vec.clear();
					for (int u = 0; u < a / i; u++) {
						for (int v = 0; v < b / i; v++) {
							string tmp = rotate(u * i, v * j, (u + 1) * i, (v + 1) * j);
							if (vec.count(tmp)) {
								cout << a << " " << b;
								return;
							}
						}
					}
				}
			}
		}
	}
}
