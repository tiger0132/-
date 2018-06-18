#include <bits/stdc++.h>
using namespace std;

#define add(x, y) x = ((x) + (y)) % MOD

const int MOD = 1000000007;

typedef long long ll;

char tmp[1500006], str[2500006];
int p[2500006];
int n;

void manacher() {
	int rb = 0, mid/*, ans = 0*/;
	for (int i = 1; i < n; i++) {
		if (i < rb) p[i] = min(p[2 * mid - i], p[mid] + mid - i);
		else p[i] = 1;
		while (str[i + p[i]] == str[i - p[i]]) p[i]++;
		if (p[i] + i > rb) {
			rb = p[i] + i;
			mid = i;
		}
		// ans = max(ans, p[i]);
	}
	// return ans-1;
}

void init() {
	memset(str, 0, sizeof str);
	memset(p, 0, sizeof p);
	n = strlen(tmp);
	int t = 2;
	str[0] = '$'; str[1] = '|';
	for (int i = 0; i < n; i++) {
		str[t++] = tmp[i];
		str[t++] = '|';
	}
	n = t;
}

int cnt[5][2500006], ans;

void modify(int index, int l, int r, int x) { // Index Librorum Prohibitorum
	if (l > r) return;
	add(cnt[index][l], x);
	add(cnt[index][r+1], MOD-x);
}

int main() {
	while (~scanf("%s", tmp)) {
		memset(cnt, 0, sizeof cnt); ans = 0;
		init();
		manacher();
		for (int i = n; i; i--) {
			modify(1, i-p[i]+1, i, i);
			modify(2, i-p[i]+1, i, 1);
		}
		for (int i = 1; i <= n; i++) {
			modify(3, i, i+p[i]-1, i);
			modify(4, i, i+p[i]-1, 1);
		}
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j <= n; j++) {
				add(cnt[i][j], cnt[i][j-1]);
			}
		}
		for (int i = 2; i < n-1; i += 2) {
			#define _ (i+2)
			ll u = (cnt[1][_] - (ll)cnt[2][_] * (_>>1) % MOD + MOD) % MOD;
			ll v = (cnt[3][i] - (ll)cnt[4][i] * (i>>1) % MOD + MOD) % MOD;
			add(ans, u * v % MOD);
		}
		printf("%d\n", ans);
	}
    return 0;
}