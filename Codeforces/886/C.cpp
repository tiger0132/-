#include <bits/stdc++.h>
using namespace std;

int n, x, ans = 1;
int vis[200005] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

int main() {
	scanf("%d", &n);
	vis[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if (!vis[x]) vis[x] = 1;
		else ans++;
		vis[i] = 0;
	}
	printf("%d", ans);
}
