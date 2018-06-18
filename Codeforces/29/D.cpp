#include <bits/stdc++.h>
using namespace std;

int n, u, v, k, x, dep[305] = {0, 1};
vector<int> tree[305]; 
int par[305] = {0, 1};
queue<int> output;
int times[305];
int path[305];

inline void dfs(int index) {
	bool leaf = true;
	for (int i : tree[index]) {
		if (!par[i]) {
			leaf = false;
			par[i] = index;
			dep[i] = dep[index] + 1;
			dfs(i);
		}
	}
	k += leaf;
}

inline int read() {
	int ret = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
    	ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
    	ret = ret * 10 + ch - 48;
		ch = getchar(); 
    }
    return ret;
}

void no() {
	cout << -1;
	exit(0);
}

int main() {
	n = read();
	for (int i = 1; i < n; i++) {
		u = read();
		v = read();
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(1); 
	for (int i = 0; i < k; i++) {
		path[i] = read();
	}
	int pos = 0;
	stack<int> st;
	while (pos != 1) {
		if (pos == 0) {
			pos = 1;
		}
		int p = pos, q = path[x++];
		int dp = dep[p];
		int dq = dep[q];
		st.push(p);
		while (dp != dq) {
			times[dp > dq ? p : q]++;
			if (times[dp > dq ? p : q] > 2) {
				no();
			}
			dp > dq ? p = par[p] : q = par[q];
			st.push(dp > dq ? p : q);
			dp--;
		}
		while (dp != dq) {
			times[p]++;
			times[q]++;
			if (times[p] > 2 || times[q] > 2) {
				no();
			}
			p = par[p];
			q = par[q];
			dp--; dq--;
			st.push(p);
			st.push(q);
		}
		while (!st.empty()) {
			cout << st.top() << endl;
			output.push(st.top());
			st.pop();
		}
	}
	while (pos != 1) {
		output.push(st.top());
		st.pop();
	}
}
