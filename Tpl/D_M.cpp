struct Node {
    struct Edge *firstEdge, *currentEdge;
    int level;
} N[MAXN];

struct Edge {
    Node *from, *to;
    int capacity, flow;
    Edge *next, *reversedEdge;

    Edge(Node *from, Node *to, int capacity) : from(from), to(to), capacity(capacity), next(from->firstEdge), flow(0) {}
};

struct Dinic {
    bool makeLevelGraph(Node *s, Node *t, int n) {
        for (int i = 0; i < n; i++) {
            N[i].level = 0;
            N[i].currentEdge = N[i].firstEdge;
        }

        std::queue<Node *> q;
        q.push(s);
        s->level = 1;

        while (!q.empty()) {
            Node *v = q.front();
            q.pop();

            for (Edge *e = v->firstEdge; e; e = e->next) {
                if (e->flow < e->capacity && e->to->level == 0) {
                    e->to->level = v->level + 1;
                    if (e->to == t) return true;
                    else q.push(e->to);
                }
            }
        }

        return false;
    }

    int findPath(Node *s, Node *t, int limit = INT_MAX) {
        if (s == t) return limit;

        for (Edge *&e = s->currentEdge; e; e = e->next) {
            if (e->flow < e->capacity && e->to->level == s->level + 1) {
                int flow = findPath(e->to, t, std::min(limit, e->capacity - e->flow));
                if (flow > 0) {
                    e->flow += flow;
                    e->reversedEdge->flow -= flow;
                    return flow;
                }
            }
        }

        return 0;
    }

    int operator()(int s, int t, int n) {
        int ans = 0;
        while (makeLevelGraph(&N[s], &N[t], n)) {
            int flow;
            while ((flow = findPath(&N[s], &N[t])) > 0) ans += flow;
        }

        return ans;
    }
} dinic;

inline void addEdge(int from, int to, int capacity) {
    N[from].firstEdge = new Edge(&N[from], &N[to], capacity);
    N[to].firstEdge = new Edge(&N[to], &N[from], 0);

    N[from].firstEdge->reversedEdge = N[to].firstEdge, N[to].firstEdge->reversedEdge = N[from].firstEdge;
}