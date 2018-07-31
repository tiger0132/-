#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

struct edge {
	int to, next;
} e[100005];

int match[5003], vis[5003];
int head[5003], cnt;

bool dfs(int x) {
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!vis[nx]) {
			vis[nx] = true;
			if (!match[nx] || dfs(match[nx])) {
				match[nx] = x;
				return true;
			}
		}
	}
	return false;
}

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
}

int n, m, k, x, y, ans, _1, _2;
char rec[102][102];
int c1[102][102];
int c2[102][102];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", rec[i]+1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (rec[i][j] == '*') {
				if (rec[i][j-1] != '*') _1++;
				c1[i][j] = _1;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (rec[i][j] == '*') {
				if (rec[i-1][j] != '*') _2++;
				c2[i][j] = _2;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			addedge(c1[i][j], c2[i][j]);
		}
	}
	for (int i = 1; i <= _1; i++) {
		memset(vis, 0, sizeof vis);
		if (dfs(i)) ans++;
	}
	printf("%d", ans);
	return 0;
} //