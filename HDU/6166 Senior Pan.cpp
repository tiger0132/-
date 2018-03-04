#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int t, n, m, x, y, z, k, dis[100001], upd[100001];
vector<pii> gph[100001];
queue<int> bfs;
int ps[100001];
int v[100001];

void spfa() {
	while (!bfs.empty()) {
		int pos = bfs.front();
		for (int i = 0; i < gph[pos].size(); i++) {
			int np = gph[pos][i].first;
			int nx = gph[pos][i].second;
			if (dis[pos] + nx < dis[np]) {
				dis[np] = dis[pos] + nx;
				upd[nx] = upd[np];
			}
		}
	}
}

int main() {
	for (scanf("%d", &t); t--; ) {
		scanf("%d%d", &n, &m);
		memset(dis, 63, sizeof dis);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x, &y, &z);
			gph[x].push_back(pii(y, z));
			gph[y].push_back(pii(x, z));
		}
		scanf("%d", &k);
		memset(dis, 63, sizeof dis);
		for (int i = 1; i <= k; i++) {
			scanf("%d", ps+i);
			dis[ps[i]] = 0;
		}
		for (int i = 0; i < 20; i++) {
			for (int j = 1; j <= k; j++) {
				if ((ps[i] >> i) & 1) {
					bfs.push(i);
					upd[i] = i;
				}
			}
			spfa();
			int mv = 0x3f3f3f3f;
			for (int i = 1; i <= n; i++) {
				mv = 
			}
			for (int j = 1; j <= k; j++) {
				if ((~(ps[i] >> i)) & 1) {
					bfs.push(i);
					upd[i] = i;
				}
			}
			// spfa();
		}
	}
	while (1);
}