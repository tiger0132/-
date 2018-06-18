#include <bits/stdc++.h>
using namespace std;

int in[202], out[202];
int gph[202][202];
int n, sp, ep;
int output[202];
long long arr[202];
// long long a2[202];
map<long long, int> rec;

int dfs(int x, int cnt) {
	output[cnt] = x;
	if (cnt > n) return 1;
	for (int i = 1; i <= n; i++) {
		if (gph[x][i]) {
			gph[x][i]--;
			if (dfs(i, cnt+1)) return 1;
			gph[x][i]++;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", arr+i);
		rec[arr[i]]++;
	}
	// memcpy(a2, arr, sizeof arr);
	sort(arr+1, arr+n+1);
	int i_ = 1;
	for (const auto& i : rec) {
		int j_ = 1;
		for (const auto& j : rec) {
			if (i_ == j_) {
				j_++;
				continue;
			}
			int ec = i.second * j.second;
			if (i.first <= 1000000000000000000 && i.first * 3 == j.first) {
				gph[j_][i_] = ec;
				in[i_] += ec;
				out[j_] += ec;
			}
			if (i.first <= 1500000000000000000 && i.first * 2 == j.first) {
				gph[i_][j_] = ec;
				out[i_] += ec;
				in[j_] += ec;
			}
			j_++;
		}
		i_++;
	}
	for (int i = 1; i <= n; i++) {
		if (out[i] == in[i] + 1) sp = i;
		if (in[i] == out[i] + 1) ep = i;
	}
	dfs(sp, 1);
	for (int i = 1; i <= n; i++) {
		printf("%I64d ", arr[output[i]]);
	}
	return 0;
}