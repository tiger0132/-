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

map<int, int> mapp;
int par[100005];

int id(int x) {
	if (!mapp.count(x)) return mapp[x] = mapp.size()+1;
	return mapp[x];
}

int find(int x) {
	return par[x] ? par[x] = find(par[x]) : x;
}

void merge(int x, int y) {
	if ((x = find(x)) != (y = find(y))) par[x] = y;
}

int n, m, x, y;
char buf[5];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%s", &x, &y, buf); x--;
		x = id(x); y = id(y);
		if (*buf == 'e') {
			if (find(x+50000) == find(y)) {
				printf("%d", i-1);
				return 0;
			}
			merge(x, y); merge(x+50000, y+50000);
		} else {
			if (find(x) == find(y)) {
				printf("%d", i-1);
				return 0;
			}
			merge(x, y+50000); merge(x+50000, y);
		}
	}
	printf("%d", m);
	return 0;
}