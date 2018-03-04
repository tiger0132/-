#include <csetjmp>
#include <vector>
#include <cstdio>
#include <queue>
#define DEBUG printf("%s %d\n", __FUNCTION__, __LINE__)
using namespace std;

const int N = 16384, INF = 0x3f3f3f3f;

struct Edge;

struct Node {
	vector<Edge> edges;
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
};

bool levelGraph(int s, int t, int n) {
	DEBUG;
	for (int i = 1; i <= n; i++) {
		gph[i].level = 0;
	}
	queue<int> bfs;
	bfs.push(s);
	gph[s].level = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = 0; i < gph[pos].edges.size(); i++) {
			const Edge& e = gph[pos].edges[i];
			if (e.flow < e.capacity && !gph[e.to].level) {
				gph[e.to].level = gph[pos].level + 1;
				if (e.to == t) return true; // ???: ????????
				else bfs.push(e.to);
			}
		}
	}
	return false;
}

int findPath(int s, int t, int flow) {
	DEBUG;
	if (s == t) return flow;
	int ret = 0;
	for (int i = 0; i < gph[s].edges.size(); i++) {
		Edge &e = gph[s].edges[i];
		if (gph[s].level + 1 == gph[e.to].level && e.flow < e.capacity) {
			int tmp = findPath(e.to, t, min(flow, e.capacity));
			flow -= tmp;
			e.flow += tmp;
			e.rev->flow -= tmp;
			ret += tmp;
			if (!flow) break; // ???: ??????????(????)
		}
	}
	if (!ret) gph[s].level = -1; // ???: ????,??DFS??
	return ret;
}

int dinic(int s, int t, int n) {
	DEBUG;
	int ans = 0;
	while (levelGraph(s, t, n)) {
		ans += findPath(s, t, INF);
	}
	return ans;
}

void addEdge(int from, int to, int capacity) {
	Edge *e1 = new Edge(from, to, capacity, 0);
	Edge *e2 = new Edge(to, from, capacity, capacity);
	e1->rev = e2;
	e2->rev = e1;
	gph[from].edges.push_back(*e1);
	gph[to].edges.push_back(*e2);
}

int n, m, s, t;
int a, b, c;

int main() {
//	#ifdef LOCAL
//	jmp_buf jmp;
//	setjmp(jmp);
//	#endif

	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		addEdge(a, b, c);
	}
	printf("%d", dinic(s, t, n));
	
//	#ifdef LOCAL
//	for (int i = 1; i <= n; i++) {
//		printf("%d: ", i);
//		for (size_t j = 0; j < gph[i].edges.size(); j++) {
//			printf("(%d, %d, %d, %d) ", gph[i].edges[j].from, gph[i].edges[j].to, gph[i].edges[j].capacity, gph[i].edges[j].flow);
//		} puts("");
//	}
//	puts("\n\n-----------------\n");
//	longjmp(jmp, 0);
//	#endif
}
