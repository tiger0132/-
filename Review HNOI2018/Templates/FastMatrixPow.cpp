#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef ll mat[102][102];

void mul(int n, mat a, const mat b) {
	mat ret = {};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				ret[i][j] = (ret[i][j] + a[i][k] * b[k][j]) % 1000000007ll;
			}
		}
	}
	memcpy(a, ret, sizeof ret);
}

void mod_pow(int n, mat b, long long p) {
	mat ret = {}, x;
	memcpy(x, b, sizeof x);
	for (int i = 1; i <= n; i++) {
		ret[i][i] = 1;
	}
	while (p) {
		if (p&1) mul(n, ret, x);
		mul(n, x, x);
		p >>= 1;
	}
	memcpy(b, ret, sizeof ret);
}

long long k;
mat src;
int n;

int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", src[i] + j);
		}
	}
	mod_pow(n, src, k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%lld ", src[i][j]);
		} puts("");
	}
	return 0;
}