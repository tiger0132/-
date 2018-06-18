#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, capacity, flow;
} e[2003];

int level[1003], head[1003], cnt;

bool bfs_(int s, int t) {
	memset(level, 0, sizeof level);
	queue<int> bfs;
	bfs.push(s);
	level[s] = 1;
	while (!bfs.empty()) {
		int pos = bfs.front(); bfs.pop();
		for (int i = head[pos]; i; i = e[i].next) {
			if (e[i].flow < e[i].capacity && !level[e[i].to]) {
				level[e[i].to] = level[pos] + 1;
				bfs.push(e[i].to);
			}
		}
	}
	return level[t];
}

int dfs(int s, int t, int flow) {
	if (s == t) return flow;
	int ret = 0;
	for (int i = head[s]; i; i = e[i].next) {
		if (level[s] + 1 == level[e[i].to] && e[i].flow < e[i].capacity) {
			int tmp = dfs(e[i].to, t, min(flow, e[i].capacity - e[i].flow));
			ret += tmp;
			e[i].flow += tmp;
			e[i^1].flow -= tmp;
			flow -= tmp;
		}
	}
	if (!ret) level[s] = -1;
	return ret;
}

int dinic(int s, int t) {
	int ret = 0;
	while (bfs_(s, t)) {
		ret += dfs(s, t, 0x3f3f3f3f);
	}
	return ret;
}

void addedge(int x, int y, int z) {
	e[++cnt] = (edge){y, head[x], z, 0}; head[x] = cnt;
	e[++cnt] = (edge){x, head[y], z, z}; head[y] = cnt;
}

/* ————————————SPLIT LINE ———————————— */ 

map<string, int> mapping;
int n, m, k, t, vcnt, f;
string buf1, buf2;

int from[102], to[102], device[102], plug[102];

int ID(const string& s) {
	if (!mapping.count(s)) mapping[s] = ++vcnt;
	return mapping[s];
}

int main() {
	buf1.resize(128);
	buf2.resize(128);
	for (scanf("%d", &t); t--; ) {
		memset(head, 0, sizeof head);
		memset(e, 0, sizeof e);
		mapping.clear();
		vcnt = 2;
		cnt = 1;
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			cin >> buf1;
			addedge(ID(buf1), 2, 1);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			cin >> buf1 >> buf2;
			int t = vcnt;
			addedge(ID(buf1), ID(buf2), 1);
			addedge(1, ID(buf1), 1);
		}
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			cin >> buf1 >> buf2;
			addedge(ID(buf1), ID(buf2), 0x3f3f3f3f);
		}
		if (f) puts("");
		printf("%d\n", m - dinic(1, 2));
		f = 1;
	}
}