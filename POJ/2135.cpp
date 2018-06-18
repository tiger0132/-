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
    int from, to, next, capacity, flow, cost;
} e[100005];

int head[5003], cnt = 1;
int prev[5003];
int flow[5003];

void ek(int s, int t, int& rflow, int& cost) {
    int dis[5003];
    int vis[5003];
    queue<int> bfs;
    while (dis[t] != 0x3f3f3f3f) {
        memset(prev, 0, sizeof prev);
        memset(flow, 0, sizeof flow);
        memset(dis, 0x3f, sizeof dis);
        memset(vis, 0, sizeof vis);
        bfs.push(s);
        flow[s] = 0x3f3f3f3f;
        dis[s] = 0;
        while (!bfs.empty()) {
            int pos = bfs.front(); bfs.pop();
            vis[pos] = 0;
            for (int i = head[pos]; i; i = e[i].next) {
                int nx = e[i].to;
                if (e[i].flow < e[i].capacity && dis[nx] > dis[pos] + e[i].cost) {
                    dis[nx] = dis[pos] + e[i].cost;
                    flow[nx] = min(flow[pos], e[i].capacity - e[i].flow);
                    prev[nx] = i;
                    if (!vis[nx]) {
                        bfs.push(nx);
                        vis[nx] = 1;
                    }
                }
            }
        }
        for (int i = prev[t]; i; i = prev[e[i].from]) {
            e[i].flow += flow[t];
            e[i^1].flow -= flow[t];
        }
        rflow += flow[t];
        cost += dis[t] * flow[t];
    }
}

void addedge(int x, int y, int z, int w) {
    e[++cnt] = (edge){x, y, head[x], z, 0, w}; head[x] = cnt;
    e[++cnt] = (edge){y, x, head[y], 0, 0, -w}; head[y] = cnt;
}

int n, m, x, y, z, rflow, cost;

int main() {
	while (~scanf("%d%d", &n, &m)) {
		memset(e, 0, sizeof e); cnt = 1;
		memset(head, 0, sizeof head);
		while (m--) {
			scanf("%d%d%d", &x, &y, &z);
			x++; y++;
			addedge(x, y, 1, z);
			addedge(y, x, 1, z);
		}
		addedge(1, 2, 2, 0);
		addedge(n+1, n+2, 2, 0);
		ek(1, n+2, rflow, cost);
		printf("%d\n", cost);
	}
}