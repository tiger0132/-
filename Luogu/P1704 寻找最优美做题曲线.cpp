#include <bits/stdc++.h>
using namespace std;

int p[500005], t[500005];
int lis[500005];
int c[500005];
int n, m, x; 
int ans;

void proc() {
	int nx = 0; *c = *t;
	for (int i = 1; i <= m; i++) {
		if (i > 1) c[++nx] = t[p[i-1]];
		for (int j = p[i-1]+1; j < p[i]; j++) {
//			printf("%d %d %d: ", t[p[i-1]], t[j], t[p[i]]);
			if (t[p[i-1]] < t[j] && t[j] < t[p[i]]) {
//				puts("success");
				c[++nx] = t[j];
			} else {
//				puts("failed");
			}
		}
	}
	c[++nx] = t[p[m]];
	for (int i = p[m]+1; i <= n; i++) {
		if (t[p[m]] < t[i]) {
			c[++nx] = t[i];
		}
	}
	c[++nx] = t[p[m]];
	n = nx;
} 

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", p+i);
	}
	sort(p+1, p+m+1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", t+i);
	}
	for (int i = 2; i <= m; i++) {
		if (t[p[i]] <= t[p[i-1]]) {
			puts("impossible");
			return 0;
		}
	}
	proc();
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(lis+1, lis+ans+1, c[i]) - lis;
		lis[pos] = c[i];
		ans = max(ans, pos);
	}
	printf("%d", ans);
}

