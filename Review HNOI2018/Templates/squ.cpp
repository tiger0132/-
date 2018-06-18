#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y;
};

int arr[8001][8001];
vector<node> rec;
int m;

int sm(int n, int x, int offset) {
    return x = (x + offset + n - 1) % n + 1;
}

void init(int n) {
    memset(arr, 0, sizeof arr);
    rec.clear();
    int x = 1, y = n / 2 + 1, c = 0;
    while (c < n * n) {
        arr[x][y] = ++c;
		rec.push_back((node){x, y});
        int nx = sm(n, x, -1);
        int ny = sm(n, y, 1);
        if (arr[nx][ny]) {
            nx = sm(n, x, 1);
            ny = y;
        }
        x = nx;
        y = ny;
    }
}

long long tx, ty, x, y, c;
int op, n, now;

int main() {
	// freopen("std.in", "r", stdin);
	// freopen("std.out", "w", stdout);
    scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &op, &n);
        if (n != now) {
            init(n);
            now = n;
        }
		if (op == 1) {
			scanf("%I64d", &x);
			printf("%d %d\n", rec[x].x, rec[x].y);
		} else {
			scanf("%I64d%I64d", &x, &y);
			printf("%d\n", arr[x][y]);
		}
    }
    return 0;
}