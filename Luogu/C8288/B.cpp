#include <bits/stdc++.h>
using namespace std;

int n, m, s, x;
int rec[100005];

int main() {
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m+1; i++) {
		if (i > m) rec[i] = n+1;
		else scanf("%d", rec+i);
		if (i > 1 && rec[i] - rec[i-2] < s) {
			puts("NO");
			return 0;
		}
	}
	// TODO: DEBUG
	if (rec[1] < s) {
		for (int i = 2; i <= m; i += 2) printf("%d", i);
		printf("%d", m+1);
		for (int i = m-1; i; i -= 2) printf("%d ", i);
		puts("0");
	} else {
		for (int i = 1; i <= m+1; i += 2) printf("%d", i);
		printf("%d", m+1);
		for (int i = m-1; i; i -= 2) printf("%d ", i);
		puts("0");
	}
	for (int i = 1; i < m; i += 2) {
		printf("%d ", i);
	} printf("%d", m+1);
	for (int i = m; ~i; i -= 2) {
		printf("%d ", i);
	}
	return 0;
}