#include <bits/stdc++.h>
using namespace std; 

int judge[100005];
int tmp[100005];
int rec[100005];
int t, n, cnt;

void check(int k) {
	memcpy(tmp, rec, sizeof rec);
	sort(tmp, tmp + k);
	for (int i = k; i < n; i += k) {
		sort(tmp + i, tmp + i + k);
		for (int j = 0; j < k; j++) {
			if (tmp[i + j] ^ tmp[i + j - k]) {
				return;
			}
		}
	}
	judge[++cnt]=k;
}

int main() {
	for (scanf("%d", &t); t--; ) {
		cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", rec+i);
		}
		for (int i = 1; i <= (n>>1); i++) if (n % i == 0) {
			check(i);
		}
		judge[++cnt] = n;
		printf("%d", judge[1]); // 卡空格太恶心啦! —— LYH
		for (int i = 2; i <= cnt; i++) {
			printf(" %d", judge[i]);
		}
		puts("");
	}
	return 0;
}