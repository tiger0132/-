#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

typedef pair<int, char> pic;

char s[5005];
int b[5005];
int a[5005];
int ans;
int n;

int main() {
	cin >> s; n = strlen(s);
	for (int i = 0; i < n; i++) {
		if (!i) {
			*a = (s[i] == 97);
			*b = (s[i] == 98);
		} else {
			a[i] = a[i-1] + (s[i] == 97);
			b[i] = b[i-1] + (s[i] == 98);
		}
//		printf("(%d, %d) ", a[i], b[i]);
	}
//	puts("");
	for (int i = 0; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			// [0, i) [i, j) [j, n)
//			printf("(%d, %d): %d, %d, %d\n", i, j, a[i-1], (b[j-1]-b[i-1]), (a[n-1]-a[j-1]));
			ans = max(ans, a[i-1] + (b[j-1]-b[i-1]) + (a[n-1]-a[j-1]));
		} 
	} 
	printf("%d", ans);
}


