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
} e[1500006];

int dfn[2003], low[2003], vis[2003], scc[2003], idx, scnt;
int head[2003], cnt;
stack<int> st;

void tarjan(int x) {
	dfn[x] = low[x] = ++idx; vis[x] = true;
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

void addedge(int x, int y) {
	e[++cnt] = (edge){y, head[x]}; head[x] = cnt;
}

bool check(int a, int b, int c, int d) {
	return (c <= a && a < d) || (c < b && b <= d) || (a <= c && b >= d);
}

int s[1003], t[1003], d[1003], val[1003];
int n, sh, sm, th, tm_;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d:%d %d:%d %d", &sh, &sm, &th, &tm_, d+i);
		s[i] = sh * 60 + sm;
		t[i] = th * 60 + tm_;
	}
	for (int i = 1; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
            if (check(s[i], s[i]+d[i], s[j], s[j]+d[j])) {
				addedge(i, n+j); addedge(j, n+i);
			}
            if (check(s[i], s[i]+d[i], t[j]-d[j], t[j])) {
				addedge(i, j); addedge(n+j, n+i);
			}
            if (check(t[i]-d[i], t[i], s[j], s[j]+d[j])) {
				addedge(n+i, n+j); addedge(j, i);
			}
            if (check(t[i]-d[i], t[i], t[j]-d[j], t[j])) {
				addedge(n+i, j); addedge(n+j, i);
			}
        }
	}
	for (int i = 1; i <= (n << 1); i++) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		if (scc[i] == scc[n + i]) {
			puts("NO");
			return 0;
		}
	}
    puts("YES");
    for (int i = 1; i <= n; i++) {
    	val[i] = scc[i] > scc[n + i];
	}
	for (int i = 1; i <= n; i++) {
		if (val[i]) {
			printf("%02d:%02d %02d:%02d\n", (t[i] - d[i]) / 60, (t[i] - d[i]) % 60, t[i] / 60, t[i] % 60);
		} else {
			printf("%02d:%02d %02d:%02d\n", s[i] / 60, s[i] % 60, (s[i] + d[i]) / 60, (s[i] + d[i]) % 60);
		}
	}
	return 0;
}