#include <bits/stdc++.h>
using namespace std;

typedef int Flow_Type;

const Flow_Type INF = 0x3f3f3f3f;
const int N = 16384;

struct Edge;

struct Node {
	vector<Edge *> edges;
	int level;
} gph[N];

struct Edge {
	Flow_Type capacity, flow;
	int from, to;
	Edge *rev;
	Edge(int from_, int to_, Flow_Type capacity_, Flow_Type flow_ = 0) {
		capacity = capacity_;
		from = from_;
		flow = flow_;
		to = to_;
	}
	Edge() {
		from = to = 0;
		capacity = flow = 0;
		rev = 0;
	}
};

bool levelGraph(int s, int t, int n) {
	for (int i = 1; i <= n; i++) {
		gph[i].level = 0;
	}
	queue<int> bfs;
	bfs.push(s);
	gph[s].level = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = 0; i < gph[pos].edges.size(); i++) {
			const Edge& e = *gph[pos].edges[i];
			if (e.flow < e.capacity && !gph[e.to].level) {
				gph[e.to].level = gph[pos].level + 1;
				if (e.to == t) return true; // 优化一
				else bfs.push(e.to);
			}
		}
	}
	return false;
}

Flow_Type findPath(int s, int t, Flow_Type flow) {
	if (s == t) return flow;
	Flow_Type ret = 0;
	for (int i = 0; i < gph[s].edges.size(); i++) {
		Edge &e = *gph[s].edges[i];
		if (gph[s].level + 1 == gph[e.to].level && e.flow < e.capacity) {
			Flow_Type tmp = findPath(e.to, t, min(flow, e.capacity - e.flow));
			flow -= tmp;
			e.flow += tmp;
			e.rev->flow -= tmp;
			ret += tmp;
			if (!flow) break; // 优化二
		}
	}
	if (!ret) gph[s].level = -1; // 优化三
	return ret;
}

Flow_Type dinic(int s, int t, int n) {
	Flow_Type ans = 0;
	while (levelGraph(s, t, n)) {
		ans += findPath(s, t, INF);
	}
	return ans;
}

int cnt = -1;

void addEdge(int from, int to, int capacity) {
	Edge *e1 = new Edge(from, to, capacity, 0);
	Edge *e2 = new Edge(to, from, capacity, capacity);
	e1->rev = e2;
	e2->rev = e1;
	gph[from].edges.push_back(e1);
	gph[to].edges.push_back(e2);
}

int t, n, m, a, b, c;

int main() {
	scanf("%d", &t);
	for (int cn = 1; cn <= t; cn++) {
		for (int i = 1; i <= n; i++) {
			gph[i].edges.clear();
		}
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
		}
		printf("Case %d: %d\n", cn, dinic(1, n, n));
	}
}