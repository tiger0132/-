#include <bits/stdc++.h>
#define m(x,i,j) (((x)>>(((i)<<2)+(j)))&1)
#define s(x,i,j) ((x)^=(1<<(((i)<<2)+(j))))
using namespace std;

const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<int> bfs;
int ans[65537];
int st, ed;
char s[2];

void 

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%1s", s);
			st = (st << 1) | (48 ^ *s);
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%1s", s);
			ed = (ed << 1) | (48 ^ *s);
		}
	}
	memset(ans, 63, sizeof(ans));
	ans[st] = 0;
	bfs.push(st);
	while (!bfs.empty()) {
		int pos = bfs.front();
		bfs.pop();
		if (pos == ed) {
			printf("%d", ans[ed]);
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];		 
					if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && m(pos, i, j) && !m(pos, nx, ny)) {
						int npos = pos;
						s(npos, i, j);
						s(npos, nx, ny);
						if (ans[npos] > ans[pos] + 1) {
							ans[npos] = ans[pos] + 1;
							bfs.push(npos);
						}
					}
				}
			}
		}
	}
}
