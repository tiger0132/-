#include <bits/stdc++.h>
using namespace std;

int t, n, ber, cnt, sp, ep;
int gph[31][31];
char buf[1003];
int ind[31];
int oud[31];
int use[31];
int vis[31];

int dfs(int x) {
    int ret = 1;
    vis[x] = 1;
    for (int i = 0; i < 26; i++) {
        if (gph[x][i] && !vis[i]) {
            ret += dfs(i);
        }
    }
    return ret;
}

int main() {
    for (scanf("%d", &t); t--; ) {
        memset(vis, 0, sizeof vis);
        memset(ind, 0, sizeof ind);
        memset(oud, 0, sizeof oud);
        memset(gph, 0, sizeof gph);
        memset(use, 0, sizeof use);
        sp = ep = ber = cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", buf);
            int x = buf[0] - 97;
            int y = buf[strlen(buf) - 1] - 97;
            gph[x][y] = gph[y][x] = 1;
            use[x] = use[y] = 1;
            ind[x]++; oud[y]++;
            ber = x;
        }
        for (int i = 0; i < 26; i++) {
            cnt += use[i];
            sp += (ind[i] == oud[i] + 1);
            ep += (ind[i] + 1 == oud[i]);
            if (abs(ind[i] - oud[i]) > 1) {
                puts("The door cannot be opened.");
                goto end;
            }
        }
        if (((sp == 1 && ep == 1) || (!sp && !ep)) && dfs(ber) == cnt) {
            puts("Ordering is possible.");
        } else {
            puts("The door cannot be opened.");
        }
        end:;
    }
}