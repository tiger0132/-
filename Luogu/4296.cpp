#include <bits/stdc++.h>
using namespace std;

set<int> ans;
int n;

int main() {
	scanf("%d", &n);
	for (int a = 1; a * a <= n; a++) if (!(n % a)) {
		for (int b = 1; b <= n; b += n / a) if (!((b+1) % a)) {
			ans.insert(b);
		}
		for (int b = n / a - 1; b <= n; b += n / a) if (!((b-1) % a)) {
			ans.insert(b);
		}
	}
	for (set<int>::const_iterator i = ans.begin(); i != ans.end(); i++) {
		printf("%d\n", *i);
	}
	return 0;
}