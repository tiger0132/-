#include <bits/stdc++.h>
using namespace std;

char arr[32][32];
int a, b;

int main() {
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << arr[j][b - i - 1];
		}
		cout << endl;
	}
}
