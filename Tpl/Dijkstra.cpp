#include <bits/stdc++.h>
#define M 23333
using namespace std;

typedef pair<int, int> pii;
queue<int> ans;
vector<pii> e;
bool vis[M]; 

void dijkstra(int s) {
	memset(dis, 63, sizeof dis);
	memset(vis, 0, sizeof vis);
	dis[s] = 0;
	for (int it = 1; it <= n; i++) {
		int mind = inf, p = -1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && dis[i] <= mind) {
				mind = dis[i];
				p = i;
			}
		}
		vis[p] = 1;
		for (int i = 0; i < e[p].size(); i++) {
			int v = e[p][i].first;
			int w = e[p][i].second;
			if (dis[v] > dis[p]+w) {
				dis[v] = dis[p]+w;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		e[x].push_back(pii(y, i));
		e[y].push_back(pii(x, i));
	}
}