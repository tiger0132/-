#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> occ;
int t, n, m, y;
ll x;

int main() {
    for (scanf("%d", &t); t--; ) {
        scanf("%d%d", &n, &m); occ.clear(); y = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &x);
            if (x == 1) continue;
            occ[x]++;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &x);
            if (x == 1) continue;
            occ[x]--;
        }
        for (map<ll, int>::const_iterator i = occ.begin(); i != occ.end(); i++) {
            y += i->second;
            if (i->second) {
                x = i->first;
            }
        }
        if (y != 1 || x == 1) {
            puts("NO");
            continue;
        }
        for (int i = 2; i*i <= x; i++) {
            if (!(x % i)) {
                puts("NO");
                goto end;
            }
        }
        puts("YES");
        end:;
    }
    return 0;
}