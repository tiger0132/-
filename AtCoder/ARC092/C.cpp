#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x, y;
} r[111], b[111];

vector<int> gph[111];
int n, x, idx[111];
int cnt[111];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &r[i].x, &r[i].y);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &b[i].x, &b[i].y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (r[i].x < b[j].x && r[i].y < b[j].y) {
				// printf("!");
				idx[i]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cnt[idx[i]]++;
	}
	for (int i = n; i >= 1; i--) {
		cnt[i] += cnt[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i]) {
			return 0;
		}
	}
	printf("%d", ans);
	return 0;
}