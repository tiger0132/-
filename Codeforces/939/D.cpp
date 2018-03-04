#include <bits/stdc++.h>
#ifdef LOCAL
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;

char a[100005], b[100005];
int par[31];
int n, ans;

int find(int x) {
	return ~par[x] ? par[x] = find(par[x]) : x;
}
void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y, ans++;
}

int main() {
	memset(par, -1, sizeof par);
	scanf("%d\n", &n);
	gets(a + 1);
	gets(b + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			int ax = a[i] - 'a';
			int bx = b[i] - 'a';
			merge(ax, bx);
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < 26; i++) {
		find(i);
		if (par[i] != -1) printf("%c %c\n", i + 'a', par[i] + 'a');
	}
}