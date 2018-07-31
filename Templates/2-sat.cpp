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
} e[2000006];

int head[2003], cnt;

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
}

int vis[2003], dfn[2003], low[2003], scc[2003], idx, scnt;
stack<int> st;

void tarjan(int x) {
	dfn[x] = low[x] = ++idx;
	vis[x] = true;
	st.push(x);
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (!dfn[nx]) {
			tarjan(nx);
			low[x] = min(low[x], low[nx]);
		} else if (vis[nx]) {
			low[x] = min(low[x], dfn[nx]);
		}
	}
	if (dfn[x] == low[x]) {
		scnt++;
		while (!st.empty()) {
			int _ = st.top(); st.pop();
			vis[_] = false;
			scc[_] = scnt;
			if (_ == x) break;
		}
	}
}

int n, m, x, y, z;
char buf[4];

int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d%s", &x, &y, &z, buf);
		x++; y++;
		switch (*buf) {
			case 'A':
				if (z) {
					addedge(x + n, x);
					addedge(y + n, y);
				} else {
					addedge(x, y + n);
					addedge(y, x + n);
				}
				break;
			case 'O':
				if (z) {
					addedge(x + n, y);
					addedge(y + n, x);
				} else {
					addedge(x, x + n);
					addedge(y, y + n);
				}
				break;
			case 'X':
				if (z) {
					addedge(x + n, y);
					addedge(x, y + n);
					addedge(y + n, x);
					addedge(y, x + n);
				} else {
					addedge(x + n, y + n);
					addedge(x, y);
					addedge(y + n, x + n);
					addedge(y, x);
				}
		}
	}
	for (int i = 1; i <= (n<<1); i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[i+n]) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}