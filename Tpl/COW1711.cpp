#include <csetjmp>
#include <cassert>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 16384, INF = 0x3f3f3f3f;

struct Edge;

struct Node {
    vector<Edge *> edges;
    int level;
} gph[N];

struct Edge {
    int from, to, capacity, flow;
    Edge *rev;
    Edge(int from_, int to_, int capacity_, int flow_ = 0) {
        capacity = capacity_;
        from = from_;
        flow = flow_;
        to = to_;
    }
	Edge() {
		from = to = capacity = flow = 0;
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

int findPath(int s, int t, int flow) {
    if (s == t) return flow;
    int ret = 0;
    for (int i = 0; i < gph[s].edges.size(); i++) {
        Edge &e = *gph[s].edges[i];
        if (gph[s].level + 1 == gph[e.to].level && e.flow < e.capacity) {
            int tmp = findPath(e.to, t, min(flow, e.capacity - e.flow));
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

int dinic(int s, int t, int n) {
    int ans = 0;
    while (levelGraph(s, t, n)) {
        ans += findPath(s, t, INF);
    }
    return ans;
}

int n, f, d, x, a, b, t, cnt = -1;
Edge edges[N];

void addEdge(int from, int to, int capacity) {
	gph[from].edges.push_back(&(edges[++cnt] = Edge(from, to, capacity, 0)));
	gph[to].edges.push_back(&(edges[++cnt] = Edge(to, from, capacity, capacity)));
	edges[cnt].rev = &edges[cnt ^ 1];
	edges[cnt ^ 1].rev = &edges[cnt];
}

int main() {
	// #ifdef LOCAL
	// jmp_buf jmp;
	// setjmp(jmp);
	// #endif

	scanf("%d%d%d", &n, &f, &d);
	t = 2 + f + 2*n + d;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		for (int j = 1; j <= a; j++) {
			scanf("%d", &x);
			addEdge(1 + x, 1 + f + i, 1);
		}
		addEdge(1 + f + i, 1 + f + n + i, 1);
		for (int j = 1; j <= b; j++) {
			scanf("%d", &x);
			addEdge(1 + f + n + i, 1 + f + 2*n + x, 1);
		}
	}
	for (int i = 1; i <= f; i++) {
		addEdge(1, 1 + i, 1);
	}
	for (int i = 1; i <= d; i++) {
		addEdge(1 + f + 2*n + i, t, 1);
	}
	printf("%d", dinic(1, t, n));

	#ifdef LOCAL
	int test = 0;
	for (int i = 0; i <= cnt; i++) {
		// if (edges[i].from < edges[i].to)
			test++,printf("%d %d %d\n", edges[i].from, edges[i].to, edges[i].capacity);
	}
	printf("\n%d %d %d %d\n", t, cnt / 2 + 1, 1, t);
	while (1);
	#endif
	// #ifdef LOCAL
	// puts("\n\n-----------------\n");
	// longjmp(jmp, 0);
	// #endif
}  