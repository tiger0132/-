#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d, dis[4][4];

void dfs(int x, int t) {
    if (t == n) {
        printf("%d", d);
        exit(0);
    }
    int u = dis[1][x], v = dis[2][x], w = dis[3][x];
    if (v >= u && w >= u) {
        d += u;
        dfs(1, t + 1);
    } else if (u >= v && w >= v) {
        d += v;
        dfs(2, t + 1);
    } else {
        d += w;
        dfs(3, t + 1);
    }
}

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    dis[1][1] = dis[2][2] = dis[3][3] = 0x3f3f3f3f;
    dis[1][2] = dis[2][1] = a;
    dis[1][3] = dis[3][1] = b;
    dis[2][3] = dis[3][2] = c;
    dfs(1, 1);
}