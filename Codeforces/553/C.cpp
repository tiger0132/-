#include <bits/stdc++.h>
using namespace std;

struct dsu {
	int par[100005];
	int find(int x) {
		return par[x] ? par[x] = find(par[x]) : x;
	}
	int merge(int x, int y) {
		return ((x = find(x)) != (y = find(y)) ? par[x] = y : 0);
	}
} a, b, c; 



int main() {
	
}
