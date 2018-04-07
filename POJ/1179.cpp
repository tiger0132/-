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

int minx[51][51];
int maxx[51][51];
char op[51];
int a[51];
int n;

int f(int x, int y, char opr) {
	if (opr == 't') return x + y;
	return x * y;
}

int main() {
	scanf("%d", &n);
	memset(minx, 0x3f, sizeof minx);
	memset(maxx, 0xcf, sizeof maxx);
	for (int i = 1; i <= n; i++) {
		scanf("%*c%c%*c%d", op+(i-2)%n+1, a+i);
		maxx[i][i] = minx[i][i] = a[i];
	}
	for (int i = 2; i <= n; i++) {
		for (int l = 1; l <= n - i + 1; l++) {
			int r = l + i - 1;
			#define left [l][k]
			#define right [k+1][r]
			#define all [l][r]
			#define opr op[k]

			maxx all = 0xcfcfcfcf;
			minx all = 0x3f3f3f3f;
			for (int k = l; k < r; k++) {
				maxx all = max(maxx all, f(maxx left, maxx right, opr));
				minx all = min(minx all, f(minx left, minx right, opr));
				if (opr == 'x') {
					maxx all = max(maxx all, f(minx left, minx right, opr));
					minx all = min(minx all, f(maxx left, minx right, opr));
					minx all = min(minx all, f(minx left, maxx right, opr));
				}
			}
		}
	}
	printf("%d", maxx[1][n]);
	return 0;
}