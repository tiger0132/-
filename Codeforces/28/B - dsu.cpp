#include <bits/stdc++.h>
using namespace std;

const int size = 128;

int fav[size], index[size];
int par[size];
int rnk[size];
int n, x;

void init() {
	for (int i = 0; i < size; i++) {
		rnk[i] = 0;
		par[i] = i;
	}
}

int find(int x) {
	return par[x] = (par[x] == x ? x : find(par[x]));
} 

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return;
	}
	if (rnk[x] < rnk[y]) {
		par[x] = y;
	} else if (rnk[x] == rnk[y]) {
		par[x] = y;
		rnk[x]++;
	} else {
		par[y] = x;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	init();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		index[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> fav[i];
		if (i - fav[i] > 0) {
			unite(i, i - fav[i]);
		}
		if (i + fav[i] <= n) {
			unite(i, i + fav[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!same(i, index[i])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
} 
