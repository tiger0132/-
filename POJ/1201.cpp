// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2017 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

// 17.4.1.2 Headers

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#endif

// C++
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

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

using namespace std;

struct edge {
	int to, next, w;
} e[2000005];

int head[50004], cnt;

int dummy1[2333];
int vis[50004];
int dis[50004];
int dummy2[2333];

int t, f, n, x, y, z;

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z}; head[x] = cnt;
	// if (t < -2) printf("%d: %d %d %d\n", cnt, x, y, z);
}

int spfa() {
	stack<int> dfs;
	dfs.push(-1);
	while (!dfs.empty()) {
		int x = dfs.top(); dfs.pop(); vis[x] = 0;
		for (int i = head[x]; i; i = e[i].next) {
			// if (t < -2)
			// printf("%d\n", i);
			int nx = e[i].to;
			if (dis[nx] < dis[x] + e[i].w) {
				dis[nx] = dis[x] + e[i].w;
				if (!vis[nx]) {
					vis[nx] = 1;
					dfs.push(nx);
				}
			}
		}
	}
}

int main() {
	for (scanf("%d", &t); t--; ) {
		head[-1] = 0;
		memset(head, 0, sizeof head); cnt = 0;
		memset(e, 0, sizeof e);
		
		if (f) puts("");
		for (scanf("%d", &n); n--; ) {
			scanf("%d%d%d", &x, &y, &z);
			addedge(x-1, y, z);
		}
		for (int i = 0; i <= 50000; i++) {
			addedge(i-1, i, 0);
			addedge(i, i-1, -1);
		}
		memset(dis, 0xcf, sizeof dis);
		dis[-1] = 0;
		spfa();
		printf("%d\n", dis[50000]); f = 1;
	}
	return 0;
}