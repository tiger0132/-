//Latest Code 

#include <iostream>
#include <cmath>
using namespace std;

bool book[20][10];
int n, m, t, coord[82][2], map[10][10], sum;
char op;

int calc(int a, int b, char c) {
	switch (c) {
		case '+': return a + b;
		case '-': return abs(a - b);
		case '*': return a * b;
		case '/': return a / b * b == a ? max(a, b) / min(a, b) : -1;
	}
}

int dfs(int index) {
	if (index == m) {
		if (op == '-' || op == '/') {
			return calc(map[coord[1][0]][coord[1][1]], map[coord[2][0]][coord[2][1]], op) == t;
		} else {
			int result = 0;
			for (int i = 1; i <= m; i++) {
				result = calc(result, map[coord[i][0]][coord[i][1]], op);
			}
			return result == t;
		}
	}
	int ret = 0;
	if (op == '+') {
		if (sum + (m - index) * n < t || sum + m - index > t) {
			return 0;
		}
		for (int i = 1; i <= min(n, t - sum); i++) {
			if (!book[coord[index + 1][0]][i] && !book[coord[index + 1][1] + 9][i]) {
				book[coord[index + 1][0]][i] = true;
				book[coord[index + 1][1] + 9][i] = true;
				map[coord[index + 1][0]][coord[index + 1][1]] = i;
				sum += i;
				ret += dfs(index + 1); 
				sum -= i;
				map[coord[index + 1][0]][coord[index + 1][1]] = 0;
				book[coord[index + 1][0]][i] = false;
				book[coord[index + 1][1] + 9][i] = false;
			}
		}
	} else if (op == '*') {
		for (int i = 1; i <= min(n, t / sum); i++) {
			if (!book[coord[index + 1][0]][i] && !book[coord[index + 1][1] + 9][i]) {
				book[coord[index + 1][0]][i] = true;
				book[coord[index + 1][1] + 9][i] = true;
				map[coord[index + 1][0]][coord[index + 1][1]] = i;
				sum *= i;
				ret += dfs(index + 1);
				sum /= i;
				map[coord[index + 1][0]][coord[index + 1][1]] = 0;
				book[coord[index + 1][0]][i] = false;
				book[coord[index + 1][1] + 9][i] = false;
			}
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (!book[coord[index + 1][0]][i] && !book[coord[index + 1][1] + 9][i]) {
				book[coord[index + 1][0]][i] = true;
				book[coord[index + 1][1] + 9][i] = true;
				map[coord[index + 1][0]][coord[index + 1][1]] = i;
				ret += dfs(index + 1);
				map[coord[index + 1][0]][coord[index + 1][1]] = 0;
				book[coord[index + 1][0]][i] = false;
				book[coord[index + 1][1] + 9][i] = false;
			}
		}
	}
	return ret;
}

int main() {
	cin >> n >> m >> t >> op;
	for (int i = 1; i <= m; i++) {
		cin >> coord[i][0] >> coord[i][1];
	}
	sum = (op == '*');
	cout << dfs(0);
}
/*
9 10 45 +
1 1 1 2 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9
*/
