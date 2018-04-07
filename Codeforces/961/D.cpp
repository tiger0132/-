#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x[100005], y[100005];
bool vis[100005];
int n;

bool check(int u, int v) {
	memset(vis, 0, sizeof vis);
	int fst = 0, snd = 0, cnt = 0;
	for (int i = 1; i <= n; i++) {
		vis[i] = ((x[u] - x[v]) * (y[u] - y[i]) == (y[u] - y[v]) * (x[u] - x[i]));
		if (fst && !snd && !vis[i]) snd = i;
		if (!fst && !vis[i]) fst = i;
		cnt += !vis[i];
	}
	if (cnt < 3) return 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && ((x[fst] - x[snd]) * (y[fst] - y[i])
					 != (y[fst] - y[snd]) * (x[fst] - x[i]))) {
			return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d%I64d", x+i, y+i);
	}
	if (n <= 3) puts("YES");
	else puts((check(1, 2) || check(1, 3) || check(2, 3)) ? "YES" : "NO");
	return 0; 
}