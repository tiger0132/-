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

int tree[2000006];
int n;

inline int lowbit(int x) {
	return x&-x;
}

inline void add(int x, int y) {
	while (x <= n) {
		tree[x] += y;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int ans = 0;
	while (x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

inline int query(int l, int r) {
	return query(r) - query(l-1);
}

long long ans1, ans2;
int x;

int main() {
	freopen("in.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		add(x, 1);
		ans1 += (long long)query(x+1, n) * (n - x - query(x+1, n));
		ans2 += (long long)query(1, x-1) * (x - 1 - query(1, x-1));
	}
	printf("%lld %lld", ans1, ans2);
	while (1);
	return 0;
}
#endif