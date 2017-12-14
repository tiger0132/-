/*
作者:tiger0132
题目:p3027 线段覆盖 2
*/

#include <bits/stdc++.h>
using namespace std;

struct seg {
    int s, e, x;
    int operator<(const seg& val) const {
        return e < val.e;
    }
} inp;

vector<pair<int, int>> v;
vector<seg> rec;
int dp[1024], n;

int main() {
    for (scanf("%d", &n); n--; ) {
        scanf("%d%d%d", &inp.s, &inp.e, &inp.x);
        rec.push_back(inp);
        v.push_back(make_pair(inp.s, inp.e));
    }
    for (register int i = 0; i < rec.size(); i++)
    sort(rec.begin(), rec.end());
    for (register int i = 0; i < rec.size(); i++) {
        register int pos = 0;
        dp[i] = dp[i - 1];
        while (pos <= i) {
            dp[i] = max(dp[i], dp[rec[pos].s] + rec[pos].x);
            pos++;
        }
        // printf("%d ", dp[rec[i].e]);
    }
    printf("%d", dp[rec.back().e]);
}