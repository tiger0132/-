#include <bits/stdc++.h>
using namespace std;

map<int, int> rec;
int n, x, a;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		rec[x]++;
	}
	for (const pair<int, int>& i : rec) {
		if (i.second < i.first) {
			a += i.second;
		} else {
			a += i.second - i.first;
		}
	}
	printf("%d", a);
}
