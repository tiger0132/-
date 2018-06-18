#include <bits/stdc++.h>
using namespace std;

bool vis[100005];
int n, m;

int main() {
    freopen("rand.in", "r", stdin);
    freopen("rand.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        vis[i] = true;
        n = (n<<1) % m;
        if (vis[n]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
}