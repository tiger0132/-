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
} e[10004];

int match[1003], vis[1003];
int head[1003], cnt;

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

int n, m, k, x, y, ans;

int main() {
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		memset(head, 0, sizeof head); cnt = ans = 0;
		memset(match, 0, sizeof match);
		while (k--) {
			scanf("%*d%d%d", &x, &y);
			if (x && y) addedge(x, y);
		}
		for (int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof vis);
			if (dfs(i)) ans++;
		}
		printf("%d\n", ans);
	}
} //