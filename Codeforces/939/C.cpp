#include <bits/stdc++.h>
#ifdef LOCAL
#define lld "%lld"
#else
#define lld "%I64d"
#endif
using namespace std;

long long arr[200005];
long long ax, ai, cur;
int n, s, f, t;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", arr+i);
	}
	scanf("%d%d", &s, &f);
	s--; f -= 2;
	for (int i = s; i <= f; i++) {
		cur += arr[i];
	}
	for (int i = 1; i <= n; i++) {
		if (cur >= ax) {
			ai = t + 1;
			ax = cur;
		}
		f = (f + 1) % n;
		cur += arr[f] - arr[s];
		s = (s + 1) % n;
		t = (t + n - 1) % n;
	}
	printf(lld, ai);
	#ifdef LOCAL
	getchar();
	getchar();
	#endif
}

#if 0
10
5827 8450 8288 5592 6627 8234 3557 7568 4607 6949
2 10
#endif