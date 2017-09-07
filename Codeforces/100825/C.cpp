//Latest Code 

#include <windows.h>
#include <iostream>
#include <cmath>
using namespace std;

int n, m, t, coord[128][2], map[16][16], cnt;
bool book[20][10];
char op;

__attribute__((optimize("-O3"))) inline void add(register int index, register int ans) {
	if (ans + (m - index) * n < t || ans + m - index > t) {
		return;
	}
	if (index == m) {
		cnt += (map[coord[t - ans][0]][coord[t - ans][1]] == t - ans);
	}
	for (register int i = 1; i <= min(n, t - ans); i++) {
		if (!book[coord[index + 1][0]][i] && !book[coord[index + 1][1] + 64][i]) {
			book[coord[index + 1][0]][i] = true;
			book[coord[index + 1][1] + 64][i] = true;
			map[coord[index + 1][0]][coord[index + 1][1]] = i;
			add(index + 1, ans + i); 
			map[coord[index + 1][0]][coord[index + 1][1]] = 0;
			book[coord[index + 1][0]][i] = false;
			book[coord[index + 1][1] + 64][i] = false;
		}
	}
	
	if (ans + (m - index) * n < t || ans + m - index > t) {
		return;
	}
	if (index == m) {
        for (int i = 0; i < m; i++) {
            cout << map[x[i]][y[i]] << " ";
        }
        cout << endl;
		cnt += (map[x[t - ans]][y[t - ans]] == t - ans);
        return;
	}
	for (register int i = 1; i <= min(n, (int)t - ans); i++) {
		if (!(row[x[index]] & (1 << i)) && !(col[y[index]] & (1 << i))) {
			row[x[index]] |= 1 << i;
			col[x[index]] |= 1 << i;
			map[x[index]][y[index]] = i;
			add(index + 1, ans + i); 
			map[x[index]][y[index]] = 0;
			row[x[index]] ^= 1 << i;
			col[y[index]] ^= 1 << i;
		}
	}
}

int main() {
	cin >> n >> m >> t >> op;
	for (register int i = 1; i <= m; i++) {
		cin >> coord[i][0] >> coord[i][1];
	}
	switch (op) {
		case '+': add(0, 0); break;
		case '*': /*mul(0, 1)*/; break;
	}
	cout << cnt;
}
/*
9 9 45 +
1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9

10 10 55 +
1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10

9 10 55 +                 
	register int cnt = 0;
1 1 1 2 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
9 10 55 +
1 1 1 2 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
*/
