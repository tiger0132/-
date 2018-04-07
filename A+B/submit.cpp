#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <cstdio>
using namespace std;

void WA() { puts("WA"); }
void AC() {
	int a, b;
	while (~scanf("%d%d", &a, &b)) printf("%d\n", a+b);
}
void RE() { assert(0); }
void TLE() { for(;;); }
void MLE() { for(;; new long long[99999]); }
void OLE() { for(;;) puts(string(99999, '!').c_str()); }
void RF() { system("shutdown now"); system("shutdown -s -t 0"); } // Maybe WA

#ifdef TIGER0132_COMPILER_BOMB
// DO NOT COMPILE UNLESS YOU KNOW WHAT ARE YOU DOING

struct x struct z<x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(x(y,x(y><y*,x(y*w>v<y*,w,x{}
#endif

int main() {
	#ifdef TIGER0132_RF
	for (;;) fork(); // Maybe TLE
	#endif
	AC();
	return 0;
}

// Source:

#if 0
#include <bits/stdc++.h>
using namespace std;

vector<int> gph[1024];
int dp[1024][1024];
int sc[1024];
int n, m, k;

void dfs(int x) {
    for (int i = 1; i <= m; i++) dp[x][i] = sc[x];
    for (int i = 0; i < gph[x].size(); i++) {
        int nx = gph[x][i];
        dfs(nx);
        for (int j = m; j; j--) {
            for (int k = 0; k < j; k++) {
                dp[x][j] = max(dp[x][j], dp[x][j-k] + dp[nx][k]);
            }
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n;i++) {
        scanf("%d%d", &k, sc + i);
        gph[k].push_back(i);
    }
    m++;
    dfs(0);
    printf("%d", dp[0][m]);
    return 0;
}
#endif