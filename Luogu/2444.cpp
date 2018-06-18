#include <bits/stdc++.h>
using namespace std;

int trie[30004][2], cnt;
int fail[30004];
bool val[30004];

void add(const char *str) {
	int pos = 0, n = strlen(str);
	for (int i = 0; i < n; i++) {
		int nx = str[i] ^ 48;
		if (!trie[pos][nx]) {
			trie[pos][nx] = ++cnt;
			// printf("%d: %c\n", cnt, str[i]);
		}
		pos = trie[pos][nx];
	}
	val[pos] = true;
}

void ac() {
	queue<int> bfs;
	fail[0] = -1;
	for (int i = 0; i < 2; i++) {
		int& nx = trie[0][i];
		if (nx) {
			fail[nx] = 0;
			bfs.push(nx);
		}
	}
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = 0; i < 2; i++) {
			int& nx = trie[pos][i];
            if (nx) {
                fail[nx] = trie[fail[pos]][i];
				val[nx] |= val[trie[fail[pos]][i]];
                bfs.push(nx);
            } else {
                nx = trie[fail[pos]][i];
            }
		}
	}
}

bool vis[30004], v2[30004];

void dfs(int x) {
	vis[x] = true;
	for (int i = 0; i < 2; i++) {
		int nx = trie[x][i];
		if (vis[nx]) {
			puts("TAK");
			exit(0);
		} else if (!val[nx] && !v2[nx]) {
			v2[nx] = 1;
			// printf("%d -- %d\n", x, nx);
			dfs(nx);
		}
	}
	vis[x] = false;
}

char buf[30004];
int n;

int main() {
	for (scanf("%d", &n); n--; ) {
		scanf("%s", buf);
		add(buf);
	}
	ac();
	dfs(0);
	puts("NIE");
	return 0;
}