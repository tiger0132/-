#include <iostream>
#ifdef ONLINE_JUDGE
#	define DBG printf("function %s, line %d\n", __FUNCTION__, __LINE__);
#else
#	define DBG
#endif
using namespace std;

const int dir[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int spider[64][64];
int n, m, ans;

void upd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << spider[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
} 

void dfs(int dep) {
	int x, y;
	if (dep > ans) {
		return;
	}
	for (x = 1; x <= n; x++) {
		for (y = 1; y <= m; y++) {
			if (spider[x][y]) {
				goto skip;
			}
		}
	}
	ans = min(ans, dep);
	skip:
	for (int k = 0; k < 5; k++) {
		int X = x + dir[k][0];
		int Y = y + dir[k][1];
		if (X < 1 || Y < 1 || X > n || Y > m) {
			continue;
		}
		int stor[5];
		for (int r = 0; r < 5; r++) {
			stor[r] = spider[X + dir[r][0]][Y + dir[r][1]];
			spider[X + dir[r][0]][Y + dir[r][1]] = 0;
		}
//		cout << "! " << x << " " << y << endl;
//		upd();
		dfs(dep + 1);
		for (int r = 0; r < 5; r++) {
			spider[X + dir[r][0]][Y + dir[r][1]] = stor[r];
		}
//		cout << ". " << x << " " << y << endl;
//		upd();
	} 
}

int main() {
	cin >> n >> m;
	ans = n * m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			spider[i][j] = 1;
		}
	}
	dfs(0);
	cout << n * m - ans;
}
