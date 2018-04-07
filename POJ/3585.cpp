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
	int to, next, weight;
} e[400005];

int head[400005], deg[400005], f[400005], g[400005], cnt, t, n;
bool vis[400005];

void add_edge(int u, int v, int w) {
	e[++cnt] = (edge){v, head[u], w}; head[u] = cnt;
	e[++cnt] = (edge){u, head[v], w}; head[v] = cnt;
	deg[u]++; deg[v]++;
}

void dfs1(int x) {
	vis[x] = 1;
	f[x] = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (vis[nx]) continue;
		dfs1(nx);
		if (deg[nx] == 1) f[x] += e[i].weight;
		else f[x] += min(f[nx], e[i].weight);
	}
}

void dfs2(int x) {
	vis[x] = 1;
	for (int i = head[x]; i; i = e[i].next) {
		int nx = e[i].to;
		if (vis[nx]) continue;
		if (deg[x] == 1) g[nx] = f[nx] + e[i].weight;
		else g[nx] = f[nx] + min(g[x] - min(f[nx], e[i].weight), e[i].weight);
		dfs2(nx);
	}
}

int x, y, z;

int main() {
	for (scanf("%d", &t); t--; ) {
		memset(head, 0, sizeof head);
		memset(deg, 0, sizeof deg);
		memset(e, 0, sizeof e);
		memset(f, 0, sizeof f);
		memset(g, 0, sizeof g);
		cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i < n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			add_edge(x, y, z);
		}
		memset(vis, 0, sizeof vis);
		dfs1(1);
		g[1] = f[1];
		memset(vis, 0, sizeof vis);
		dfs2(1);
		printf("%d\n", *max_element(g + 1, g + n + 1));
	}
	return 0;
}