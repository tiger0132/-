#include <bits/stdc++.h>
using namespace std;

int n, need, good[256], mask[256], f[10];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> i;
		need |= (1 << i);
		f[i] = true;
	}
	for (int i = 0; i < 256; i++) {
		good[i] = true;
		int x = i;
		while (x) {
			if (!f[x % 10]) {
				good[i] = 
			}
		}
	}
	for (int i = 0; i < 256; i++) {
		if (good[i]) {
			for (int j = 0; j < 256; j++) {
				if (good[j]) {
					for (int k = 0; k < 256; k++) {
						if () {
							for (int l = 0; l < 256; l++) {
								
							}
						}
					}
				}
			}
		}
	}
}
