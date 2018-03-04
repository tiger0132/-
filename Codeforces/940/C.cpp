#include <bits/stdc++.h>
using namespace std;

char minn, nxt[998];
string src, mod;
int n, m, k;

int main() {
	cin >> n >> k >> src;
	minn = *min_element(src.begin(), src.end());
	mod = src;
	sort(mod.begin(), mod.end());
	m = unique(mod.begin(), mod.end()) - mod.begin();
	for (int i = 0; i < m-1; i++) {
		nxt[mod[i]] = mod[i + 1];
	}
	if (k > n) {
		cout << src << string(k - n, minn);
	} else {
		for (int i = k-1; i >= 0; i--) {
			if (nxt[src[i]]) {
				src[i] = nxt[src[i]];
				for (int j = i+1; j < k; j++) {
					src[j] = minn;
				}
				break;
			}
		}
		cout << src.substr(0, k);
	} puts("");
}