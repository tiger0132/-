#include <bits/stdc++.h>
using namespace std;

const int N = 1704;
int sum[N];

void build(int pos) {
	int t; scanf("%d", &t);
	if (t == -1) return;
	sum[pos] += t;
	build(pos - 1); build(pos + 1);
}

int read() {
	int t; scanf("%d", &t);
	if (t == -1) return 0;
	memset(sum, 0, sizeof sum);
	int pos = 851;
	sum[pos] = t;
	build(pos - 1); build(pos + 1);
}

int main() {
	for (int t = 1; read(); t++) {
		int pos = 0;
		while (!sum[pos]) pos++;
		printf("Case %d:\n%d", t, sum[pos++]);
		while (sum[pos]) printf(" %d", sum[pos++]);
		puts("\n");
	}
}