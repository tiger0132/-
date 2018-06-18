/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[1024][1024];
int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!(i&1) && !(j&1)) arr[i][j] = 0;
			else if (i < 3 || j < 3) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j] + arr[i][j-1] + arr[i-1][j-1];
			printf("%lld,", arr[i][j]);
		} puts("}{");
	}
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

ll arr[1024][1024];
int n, m;

void prt(ll x) {
	if (x > 9) prt(x / 10);
	putchar(x % 10 + 48);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!(i&1) && !(j&1)) arr[i][j] = 0;
			else if (i < 3 || j < 3) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j] + arr[i][j-1] + arr[i-1][j-1];
			prt(arr[i][j]);
			putchar(' ');
		} puts("");
	}
	return 0;
}