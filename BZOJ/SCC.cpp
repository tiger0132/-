#include <bits/stdc++.h>
using namespace std;

const int N = 1024, M = 4096;

struct Edge {
	int to, next;
} e[M];

int head[N];

int dfn[N], low[N], vis[N];
int dfn_index, scc_count;
stack<int> st;

void tarjan(int cur) {
	dfn[cur] = low[cur] = ++dfn_index;
	vis[cur] = 1; st.push(cur);
	for (int i = head[cur]; i; i = e[i].next) {
		int nxt = e[i].to;
		if (!dfn[nxt]) {
			tarjan(nxt);
			low[cur] = min(low[cur], low[nxt]);
		} else if (vis[nxt] && dfn[nxt] < low[cur]) {
			low[cur] = min(low[cur], dfn[nxt]);
		}
	}
	if (low[cur] == dfn[cur]) {
		scc_count++;
		while (!st.empty() && st.top() != cur) {
			// do sth.
			st.pop();
		}
	}
}

int main() {

}