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

const int oo = 0x3f3f3f3f;

int floyd[102][102];
int gph[102][102];
int lnk[102][102];
int n, m, x, y, z;
vector<int> loop;
int ans = oo;

void dfs(int x, int y) { // [x, lnk[x][y]) -- lnk[x][y] -- (lnk[x][y], y]
	if (!lnk[x][y]) return; // 无中转点
	dfs(x, lnk[x][y]); // 搜索中转点前半段
	loop.push_back(lnk[x][y]); // 路径中加入中转点
	dfs(lnk[x][y], y); // 搜索中转点后半段
}

int main() {
	scanf("%d%d", &n, &m);
	memset(gph, 0x3f, sizeof gph);
	while (m--) {
		scanf("%d%d%d", &x, &y, &z);
		gph[x][y] = gph[y][x] = min(gph[x][y], z);	
	}
	memcpy(floyd, gph, sizeof floyd);
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i < k; i++) {
			for (int j = i + 1; j < k; j++) { // 对称性, 只需搜索右上三角形部分
				if (ans > (long long)floyd[i][j] + gph[j][k] + gph[k][i]) {
					ans = floyd[i][j] + gph[j][k] + gph[k][i]; // 注意右上三角
					loop.clear();
					// i -- [中转点] -- j -- k -- i...
					loop.push_back(i);
					dfs(i, j);
					loop.push_back(j);
					loop.push_back(k);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
					floyd[i][j] = floyd[i][k] + floyd[k][j];
					lnk[i][j] = k;
				}
			}
		}
	}
	if (ans == oo) {
		puts("No solution.");
		return 0;
	}
	for (int i = 0; i < loop.size(); i++) {
		printf("%d ", loop[i]);
	}
	return 0;
}