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

struct record {
	int p, d;
	bool operator<(const record& rhs) const {
		return p > rhs.p;
	}
} rec[10004];

int par[10004];
int n, ans;

int find(int x) {
	return ~par[x] ? par[x] = find(par[x]) : x;
}

int main() {
	while (~scanf("%d", &n)) {
		memset(par, -1, sizeof par); ans = 0;
		memset(rec, 0, sizeof rec);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &rec[i].p, &rec[i].d);
		}
		sort(rec+1, rec+n+1);
		for (int i = 1; i <= n; i++) {
			int r = find(rec[i].d);
			if (r) par[r] = find(r-1), ans += rec[i].p;
		}
		printf("%d\n", ans);
	}
}