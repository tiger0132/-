#include <bits/stdc++.h>
using namespace std;

map<int, int> last;
int arr[200005];
int lnk[200005];
int dp[200005];
int n, ax, ai;

void prt(int x) {
	if (lnk[x]) prt(lnk[x]);
	printf("%d ", x);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr+i);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[last[arr[i]]], 1);
		lnk[i] = lnk[last[arr[i]]];
		if (dp[i] <= dp[last[arr[i]-1]]) {
			dp[i] = dp[last[arr[i]-1]] + 1;
			lnk[i] = last[arr[i]-1];
		}
		last[arr[i]] = i;
		if (dp[i] > ax) {
			ax = dp[i];
			ai = i;
		}
	}
	printf("%d\n", ax);
	prt(ai);
	return 0;
}