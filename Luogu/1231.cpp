#include <bits/stdc++.h>
using namespace std;

struct edge {
	int to, next, capacity, flow;
} e[2000006];

int level[200005], head[200005], cnt = 1;

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

// 练习册 书 答案
int n1, n2, n3, m, x, y;

#define spec(x) n1+n2+n2+n3+x
#define answer(x) n1+n2+n2+x
#define book1(x) n1+x
#define book2(x) n1+n2+x
#define practise(x) x

int main() {
	scanf("%d%d%d%d", &n2, &n1, &n3, &m);
	for (int i = 1; i <= n1; i++) {
		addedge(spec(1), practise(i), 1);
	}
	while (m--) {
		// 练习册 书
		scanf("%d%d", &y, &x);
		addedge(practise(x), book1(y), 1);
	}
	for (int i = 1; i <= n2; i++) {
		addedge(book1(i), book2(i), 1);
	}
	scanf("%d", &m);
	while (m--) {
		// 书 答案
		scanf("%d%d", &x, &y);
		addedge(book2(x), answer(y), 1);
	}
	for (int i = 1; i <= n3; i++) {
		addedge(answer(i), spec(2), 1);
	}
	printf("%d", dinic(spec(1), spec(2)));
	return 0;
}