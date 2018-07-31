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

int tree[8003];
int rec[8003];
stack<int> st;
int n;

inline int lowbit(int x) {
	return x&-x;
}

inline void add(int x, int y) {
	while (x <= n) {
		tree[x] += y;
		x += lowbit(x);
	}
}

inline int query(int x) {
	int ret = 0;
	while (x) {
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	add(1, 1);
	for (int i = 2; i <= n; i++) {
		scanf("%d", rec+i);
		add(i, 1);
	}
	for (int i = n; i > 1; i--) {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l+r)>>1;
			if (query(mid) >= rec[i]+1) {
				r = mid;
			} else {
				l = mid+1;
			}
		}
		st.push(l);
		add(l, -1);
	}
	for (int i = 1; i <= n; i++) {
		if (query(i)) {
			printf("%d\n", i);
			break;
		}
	}
	while (!st.empty()) {
		printf("%d\n", st.top()); st.pop();
	}
	return 0;
}