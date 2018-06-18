#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int head, tail = 1;
int que[100015];
ll pre[100015];
ll dp_[100015];
ll dp[100015];
int n, k;

const int N=1<<20;
char buf[N], *ptr = buf;

inline int read() {
	int k = 0;
	while (!isdigit(*ptr)) ++ptr;
	while (isdigit(*ptr)){
		k = k * 10 + (*ptr++ ^ 48);
	}
	return k;
}

inline void add(int x) {
	dp_[x] = dp[x-1] - pre[x];
	while (head <= tail && dp_[que[tail]] < dp_[x]) tail--;
	que[++tail] = x;
}

inline ll query(int x) {
	while (head <= tail && que[head] < x-k) head++;
	return dp_[que[head]];
}

int main() {
	fread(buf, 1, N, stdin);
	n = read();
	k = read();
	for (int i = 1; i <= n; i++) {
		pre[i] = read();
		pre[i] += pre[i-1];
	}
	for (int i = 1; i <= n; i++) {
		add(i);
		dp[i] = pre[i] + query(i);
	}
	printf("%lld", dp[n]);
	#ifdef __TIGER0133__
	while (1);
	#endif
}