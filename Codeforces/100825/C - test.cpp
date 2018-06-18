#include <iostream>
using namespace std;

int row[16], col[16];
int x[16], y[16];
int map[16][16];
int ux, uy, cnt;

long long t;
int n, m;
char op;

void add(register int index, register int ans) {
    if (ans + (m - index + 1) * n < t || ans + m - index + 1 > t) {
		return;
	}
	if (index == m) {
		cnt += t == ans;
	}
	for (register int i = 1; i <= min(n, (int)t - ans); i++) {
		if (!(row[x[index]] & (1 << (i - 1))) && !(col[y[index]] & (1 << (i - 1)))) {
			row[x[index]] |= 1 << (i - 1);
			col[x[index]] |= 1 << (i - 1);
			map[x[index]][y[index]] = i;
			add(index, ans + i); 
			map[x[index]][y[index]] = 0;
			row[x[index]] ^= 1 << (i - 1);
			col[y[index]] ^= 1 << (i - 1);
		}
	}
}

int main() {
    cin >> n >> m >> t >> op;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
    }
    switch (op) {
        case '+': add(0, 0); cout << cnt; break;
        case '-': cout << (n - t) * 2; break;
        case '*': ; break;
        case '/': cout << (n / t) * 2; break;
    }
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}
/*
9 9 45 +
1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9

10 10 55 +
1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10

9 10 55 +
1 1 1 2 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
*/
