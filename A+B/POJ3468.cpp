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

long long rec2[200005];
long long rec[200005];
long long inp[200005];
long long l, u, v, w;
char op[5];
int n, m;

inline int lowbit(int x) {
	return x&-x;
}

void add(int i, long long x, long long *arr) {
	for (; i <= n; i += lowbit(i)) arr[i] += x;
}

long long query(int i, long long *arr) {
	long long ret = 0;
	for (; i; i -= lowbit(i)) ret += arr[i];
	return ret;
}

int main() {
    scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
        scanf("%lld", inp + i);
		add(i, inp[i] - l, rec);
		add(i, (i - 1) * (inp[i] - l), rec2);
		l = inp[i];
	}
	for (int i = 1; i <= m; i++) {
        scanf("%s%lld%lld", op, &u, &v);
		if (*op == 'C') {
            scanf("%lld", &w);
			add(u, w, rec);
			add(v + 1, -w, rec);
			add(u, w * (u - 1), rec2);
			add(v + 1, -w * v, rec2);
		} else {
            printf("%lld\n", query(v, rec) * v - query(v, rec2) - query(u - 1, rec) * (u - 1) + query(u - 1, rec2));
		}
	}
	return 0;
}