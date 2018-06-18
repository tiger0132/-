#include <bits/stdc++.h>
using namespace std;

int trie[1000006][26], cnt;
int fail[1000006];
int val[1000006];

void add(const char *str) {
	int pos = 0, n = strlen(str);
	for (int i = 0; i < n; i++) {
		int nx = str[i] - 97;
		if (!trie[pos][nx]) {
			trie[pos][nx] = ++cnt;
		}
		pos = trie[pos][nx];
	}
	val[pos]++;
}

void ac() {
	queue<int> bfs;
	fail[0] = 0;
	for (int i = 0; i < 26; i++) {
		int nx = trie[0][i];
		if (nx) {
			fail[nx] = 0;
			bfs.push(nx);
		}
	}
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = 0; i < 26; i++) {
			int nx = trie[pos][i];
			if (nx) {
				fail[nx] = trie[fail[pos]][i];
				bfs.push(nx);
			} else {
				nx = trie[fail[pos]][i];
			}
		}
	}
}

int query(const char *str) {
	int pos = 0, ans = 0, n = strlen(str);
	for (int i = 0; i < n; i++) {
		pos = trie[pos][str[i] - 97];
		for (int t = pos; t && ~val[t]; t = fail[t]) {
			ans += val[t];
			val[t] = -1;
		}
	}
	return ans;
}

char buf[1000006];
int n;

int main() {
	// freopen("C:\\Users\\Administrator\\Documents\\testdata.in", "r", stdin);
	for (scanf("%d", &n); n--; ) {
		scanf("%s", buf);
		add(buf);
	}
	ac();
	scanf("%s", buf);
	printf("%d", query(buf));
	return 0;
}