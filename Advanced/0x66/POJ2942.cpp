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

int gph[1003][1003];

int n, m, dfn[1003], low[1003], color[1003], deg[1003];
int dfn_index, dcc_count;
vector<int> dcc[1003];
int flag[1003];
int now[1003];
stack<int> st;

void dfs(int x, int root) {
	dfn[x] = low[x] = ++dfn_index;
	st.push(x);
	if (x == root && !deg[x]) {
		dcc[++dcc_count].push_back(x);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!gph[x][i]) continue;
		if (!dfn[i]) {
			dfs(i, root);
			low[x] = min(low[x], low[i]);
			if (low[i] >= dfn[x]) {
				dcc_count++;
				int pos;
				do {
					pos = st.top(); st.pop();
					dcc[dcc_count].push_back(pos);
				} while (pos != i);
				dcc[dcc_count].push_back(x);
			}
		} else low[x] = min(low[x], dfn[i]);
	}
}

bool dfs2(int x, int y, int z) {
	color[x] = y;
	for (int i = 1; i <= n; i++) {
		if (now[i] != z || !gph[x][i] || x == i) continue;
		if (color[i] == y || (!color[i] && dfs2(i, -y, z))) return true;
	}
	return false;
}

void addedge(int x, int y) {
	gph[x][y] = gph[y][x] = 0;
	deg[x]++; deg[y]++;
}

int x, y, ans;

int main() {
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		memset(gph, 0, sizeof gph); ans = 0;
		memset(color, 0, sizeof color);
		memset(flag, 0, sizeof flag);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		memset(deg, 0, sizeof deg);
		memset(now, 0, sizeof now);
		for (int i = 1; i <= dcc_count; i++) dcc[i].clear();
		dcc_count = dfn_index = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				gph[i][j] = 1;
			}
		}
		while (m--) {
			scanf("%d%d", &x, &y);
			addedge(x, y);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) dfs(i, -1);
		}
		for (int i = 1; i <= dcc_count; i++) {
			for (int j = 0; j < dcc[i].size(); j++) {
				now[dcc[i][j]] = i;
			}
			memset(color, 0, sizeof color);
			if (dfs2(dcc[i][0], 1, i))  for (int j = 0; j < dcc[i].size(); j++) {
				flag[dcc[i][j]] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			ans += !flag[i];
		}
		printf("%d\n", ans);
	}
}
