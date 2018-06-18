#include <bits/stdc++.h>
using namespace std;

const int N = 4, INF = 0x7fffffff;

struct Edge;

struct Node {
    vector<Edge *> edges;
    int level;
} gph[N];

struct Edge {
    int from, to, capacity, flow;
    Edge *rev;
    Edge(int from_ = 0, int to_ = 0, int capacity_ = 0, int flow_ = 0) {
        capacity = capacity_;
        from = from_;
        flow = flow_;
        to = to_;
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
                if (e.to == t) return true;
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
            if (!flow) break;
        }
    }
    if (!ret) gph[s].level = -1;
    return ret;
}

int dinic(int s, int t, int n) {
    int ans = 0;
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

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    addEdge(1, 3, a);
    addEdge(1, 2, b);
    addEdge(2, 3, b);
    printf("%d", dinic(1, 3, 3));
}