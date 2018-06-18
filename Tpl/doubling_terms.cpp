#include <bits/stdc++.h>
using namespace std;

int pre[20004];
int dif[20004];
int rec[20004];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", rec+i);
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = rec[i];
		for (int j = 1; j < i; j++) {
			int t = pre[j];
			pre[j] = pre[i];
			pre[i] -= t;
		}
		dif[i] = pre[i];
		printf("%d ", dif[i]);
	}
	return 0;
}

// 6
// 1 32 243 1024 3125 7776