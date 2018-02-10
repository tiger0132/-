#include <bits/stdc++.h>
using namespace std;

typedef bitset<10005> record_type[15];

record_type rec;
int r, c, a, x;

int proc(int mask) {
	record_type rt;
	int ret = 0;
	copy(rec, rec+r, rt);
	for (int i = 0; i < r; i++) {
		if ((mask>>i)&1) rt[i].flip();
	}
	for (int i = 0; i < c; i++) {
		int a = 0, b = 0;
		for (int j = 0; j < r; j++) {
			a += rt[j][i];
			b += ~rt[j][i];
		}
		ret += max(a, b);
	}
	return ret; 
}

int main() {
	// freopen("b.in", "r", stdin);
	// freopen("b.out", "w", stdout);
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &x);
			rec[i][j] = x;
		}
	}
	for (int i = 0; i < (1 << r); i++) {
		a = max(a, proc(i));
	}
	printf("%d", a);
}