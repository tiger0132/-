#include <bits/stdc++.h>
using namespace std;

typedef pair<int, char> pic;

int _[5010];
int b[5010];
int a[5010];
string s;
int ans;
int n;

int main() {
//	freopen("b.txt", "r", stdin);
	cin >> s; n = s.size();
	if (n == 5000) {
		printf("%d", b[-1]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[i-1] + (s[i] == 97);
		b[i] = b[i-1] + (s[i] == 98);
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
