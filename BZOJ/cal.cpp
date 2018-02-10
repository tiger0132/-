#include <bits/stdc++.h>
using namespace std;

const int n = 513, m = 131072, mod = 1000000007;

//f_{n,m}=\sum_{k=1}^nf_{n-1,m-k+1}

int f[5000005];
int g[5000005];



int main() {
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		memcpy(g, f, sizeof g);
		memset(f, 0, sizeof f);
		int size = i*(i-1)/2;
		for (int j = 1; j <= size; j++) {
			g[j] = (g[j] + g[j-1]) % mod;
		}
		for (int j = 0; j <= size; j++) {
			f[j] = g[j];
			if (j >= i) f[j] = (g[j] - g[j-i] + mod) % mod;
		}
	}
	printf("%d", f[m]);
}
//500	100000:	743676071
//512	131072:	0
//1000	400000:	661536329
//1704	170416:	773161996
