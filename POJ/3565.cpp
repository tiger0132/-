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

// Min Cost Flow Template by tiger0132

struct edge {
	int from, to, next, capacity, flow;
	double cost;
} e[100005];

int head[1003], cnt = 1;
int flow[1003];
int pre[1003];

void ek(int s, int t, int& rflow, double& cost) {
	double dis[1003];
	int vis[1003];
	queue<int> bfs;
	while (1) {
		memset(pre, 0, sizeof pre);
		memset(flow, 0, sizeof flow);
		for (int i = 0; i < 1003; i++) {
			dis[i] = 1 << 30;
		}
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
					pre[nx] = i;
					if (!vis[nx]) {
						bfs.push(nx);
						vis[nx] = 1;
					}
				}
			}
		}
		if (!pre[t]) break;
		for (int i = pre[t]; i; i = pre[e[i].from]) {
			e[i].flow += flow[t];
			e[i^1].flow -= flow[t];
		}
		rflow += flow[t];
		cost += dis[t] * flow[t];
	}
}

void addedge(int x, int y, int z, double w) {
	e[++cnt] = (edge){x, y, head[x], z, 0, w}; head[x] = cnt;
	e[++cnt] = (edge){y, x, head[y], 0, 0, -w}; head[y] = cnt;
}

// SOLUTION:

struct xy {
	int x, y;
} l[102], r[102];

double cost;
int n, rflow;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i].x, &l[i].y);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &r[i].x, &r[i].y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int val = (l[i].x-r[j].x) * (l[i].x-r[j].x) + (l[i].y-r[j].y) * (l[i].y-r[j].y);
			addedge(i, j+n, 1, sqrt(val));
		}
	}
	for (int i = 1; i <= n; i++) {
		addedge(300, i, 1, 0);
		addedge(i+n, 301, 1, 0);
	}
	ek(300, 301, rflow, cost);
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].next) {
			if ((1&~j) && e[j].flow) {
				printf("%d\n", e[j].to - n);
				break;
			}
		}
	}
	return 0;
}