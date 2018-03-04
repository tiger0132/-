#include <bits/stdc++.h>
using namespace std;

typedef int Flow_Type;

const Flow_Type INF = 0x3f3f3f3f;
const int N = 31, M = 1003;

struct Edge;

int level[N];
int head[N];

struct Edge {
	Flow_Type capacity, flow;
	int to, next;
} e[M << 1];

bool levelGraph(int s, int t) {
	memset(level, 0, sizeof level);
	queue<int> bfs;
	bfs.push(s);
	level[s] = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = head[pos]; i; i = e[i].next) {
			if (e[i].flow < e[i].capacity && !level[e[i].to]) {
				level[e[i].to] = level[pos] + 1;
				if (e[i].to == t) return true; // 优化一
				else bfs.push(e[i].to);
			}
		}
	}
	return false;
}

Flow_Type findPath(int s, int t, Flow_Type flow) {
	if (s == t) {
		return flow;
	}
	Flow_Type ret = 0;
	for (int i = head[s]; ret < flow && i; i = e[i].next) {
		if (level[s] + 1 == level[e[i].to] && e[i].flow < e[i].capacity) {
			Flow_Type tmp = findPath(e[i].to, t, min(e[i].capacity - e[i].flow, flow));
			ret += tmp;
			flow -= tmp;
			e[i].flow += tmp;
			e[i ^ 1].flow -= tmp;
			// if (!flow) break; // 优化二
		}
	}
	if (!ret) level[s] = -1; // 优化三
	return ret;
}

Flow_Type dinic(int s, int t) {
	Flow_Type ans = 0;
	while (levelGraph(s, t)) {
		ans += findPath(s, t, INF);
	}
	return ans;
}

int cnt = 1;

void addUndirectedEdge(int from, int to, int capacity) {
	// printf("(%d, %d, %d)\n", from, to, capacity);
	e[++cnt].to = to; e[cnt].next = head[from]; e[cnt].capacity = capacity; head[from] = cnt;
	e[++cnt].to = from; e[cnt].next = head[to]; e[cnt].capacity = capacity; head[to] = cnt;
}

void addDirectedEdge(int from, int to, int capacity) {
	// printf("(%d, %d, %d)\n", from, to, capacity);
	e[++cnt].to = to; e[cnt].next = head[from]; e[cnt].capacity = capacity; head[from] = cnt;
	e[++cnt].to = from; e[cnt].next = head[to]; e[cnt].capacity = capacity; e[cnt].flow = capacity; head[to] = cnt;
}

int t, n, m, a, b, c;

int main() {
	scanf("%d", &t);
	for (int cn = 1; cn <= t; cn++) {
		cnt = 1;
		memset(e, 0, sizeof e);
		memset(head, 0, sizeof head);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			addDirectedEdge(a, b, c);
		}
		printf("Case %d: %d\n", cn, dinic(1, n));
	}
}