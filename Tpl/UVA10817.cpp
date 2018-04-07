#include <bits/stdc++.h>
using namespace std;

const int oo = 0x3f3f3f3f;

int n, m, s, t, cost[233], state[233], dp[233][512][512];

int dfs(int x, int s0, int s1, int s2) {
	if (x == n + m) return s2 == (1 << s) - 1 ? 0 : oo;
	int& ans = dp[x][s1][s2];
	if (ans >= 0) return ans;
	ans = oo;
	if (x >= m) ans = dfs(x + 1, s0, s1, s2);
	int m0 = state[x] & s0;
	int m1 = state[x] & s1;
	s0 ^= m0;
	s1 = (s1 ^ m1) | m0;
	s2 |= m1;
	ans = min(ans, cost[x] + dfs(x + 1, s0, s1, s2));
	return ans;
}

int main() {
	// freopen("xxx.in", "w", stdout);
	string buf;
	while (getline(cin, buf)) {
		memset(state, 0, sizeof state);
		memset(cost, 0, sizeof cost);
		memset(dp, -1, sizeof dp);
		stringstream ccin(buf);
		ccin >> s >> m >> n;
		if (!s) break;
		for (int i = 0; i < m + n; i++) {
			getline(cin, buf);
			stringstream cccin(buf);
			cccin >> cost[i];
			while (cccin >> t) state[i] |= (1 << (t - 1));
		}
		printf("%d\n", dfs(0, (1 << s) - 1, 0, 0));
	}
	return 0;
}