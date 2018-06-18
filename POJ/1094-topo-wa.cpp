// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2017 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed deg the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described deg the GCC Runtime Library Exception, version
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

char x, y, buf[4];
int gph[31][31];
queue<int> out;
int mask, ord;
int deg[31];
bool circ;
int n, m;

int tsort() {
	int flag = 0, pos, cnt = 0, tmp[31];
	memcpy(tmp, deg, sizeof deg);
	bool unable = 0;
	while (!out.empty()) out.pop();
	stack<int> topo;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) topo.push(i);
	}
	while (!topo.empty()) {
		if (topo.size() > 1) {
			unable = 1;
		}
		pos = topo.top();
		topo.pop();
		cnt++;
		out.push(pos);
		for (int i = 1; i <= n; i++) {
			if (gph[pos][i] == 1 && --tmp[i] == 0) {
				topo.push(i);
			}
		}
	}
	if (cnt != n) return 1;
	if (unable) return 0;
	return 233; 
} 

int main() {
	while (~scanf("%d%d", &n, &m) && (n || m)) {
		while (!out.empty()) out.pop();
		memset(gph, 0, sizeof gph);
		memset(deg, 0, sizeof deg);
		circ = ord = 0;

		for (int i = 1; i <= m; i++) {
			scanf("%s", buf);
			x = buf[0];
			y = buf[2];

			x -= 64; y -= 64;
			gph[x][y] = 1, mask |= (1 << y);
			deg[y]++;

			if (circ || ord) continue;
			if (gph[x][y] && gph[y][x]) circ = 1;
			int res = tsort();
			if (res == 1) {
				circ = 1;
				printf("Inconsistency found after %d relations.\n", i);
			}
			if (res == 233) {
				ord = i;
			}
		}

		if (circ) continue;
		if (!ord) {
			puts("Sorted sequence cannot be determined.");
		} else {
			printf("Sorted sequence determined after %d relations: ", ord);
			while (!out.empty()) {
				putchar(out.front() + 64);
				out.pop();
			}
			puts(".");
		}
	}
	return 0;
}