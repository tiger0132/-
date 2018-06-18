#include <bits/stdc++.h>
using namespace std;

int ans[10004], n, len, _, out;

int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &i, &len);
		while (scanf("%d", &_), _) {
			ans[i] = max(ans[_], ans[i]);
		}
		out = max(ans[i] += len, out);
	} 
	printf("%d", out);
}