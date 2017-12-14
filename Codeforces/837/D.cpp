#include <bits/stdc++.h>
using namespace std;

int n, v, c[16384], w[16384], dp[16384];

int main() {
    scanf("%d%d", &v, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", c + i, w + i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        }
    }
    printf("%d", dp[v]);
}