#include <bits/stdc++.h>
using namespace std; 

int n, x, y, l, k;
int c[6];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		for (int j = 1; j <= 5; j++) {
			if ((j == x || j == y) && l <= ++c[j]) {
				l = c[j];
				k = j;
			}
			else c[j] = 0;
		}
	}
	printf("%d %d", l, k);
} 
