#include <iostream>
using namespace std;

int spider[64][64];
int a, b, c, d, e;
int n, m, ans;

void dfs(int dep) {
	bool empty = true;
//	TODO: 最优性剪枝 
//	TODO: 相差甚远, 无法比较 
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= m; y++) {
			if (spider[x][y]) {
//				TODO:不可描述 
				empty = false;
				a = spider[x][y];
				b = spider[x - 1][y];
				c = spider[x + 1][y];
				d = spider[x][y - 1];
				e = spider[x][y + 1];
				spider[x][y] = spider[x - 1][y] = spider[x + 1][y] = spider[x][y - 1] = spider[x][y + 1] = 0;
				dfs(dep + 1);
				spider[x][y] = a;
				spider[x - 1][y] = b;
				spider[x + 1][y] = c;
				spider[x][y - 1] = d;
				spider[x][y + 1] = e;
			} 
		}
	}
	if (empty) {
		ans = min(ans, dep);
	}
}

int main() {
	ans = 0x3f3f3f3f;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			spider[i][j] = 1;
		}
	}
	dfs(0);
	cout << n * m - ans;
}
