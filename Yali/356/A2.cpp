#include <cstdio>
#include <cstring>

typedef long long ll;

using namespace std;
const int N = 1500;
const int MOD = 1e9 + 7;

int Scan() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * f;
}

struct Edge {
    int to, next;
} edge[N*2];
int head[N], cntE;
void addedge(int u, int v) {
    edge[cntE].to = v; edge[cntE].next = head[u]; head[u] = cntE++;
    edge[cntE].to = u; edge[cntE].next = head[v]; head[v] = cntE++;
}
int a[N], n, m;

int sz[N];      // sz[u] 记录 根为 u 点 有多少个异或值
int val[N][N];  // val[u][i] 记录 u 点 第 i 个的异或值都是什么
int dp[N][N];   // dp[u][i] 记录 根为 u 点 异或值为i的数量
int vis[N][N];  // vis[i] 记录 i 这个 异或值是否出现过
int tmp[N];

void add(int &a, int b) {
    a = ((ll)a + b) % MOD;
}

void dfs(int u, int fa) {
    dp[u][ a[u] ] = 1;
    val[u][ sz[u]++ ] = a[u];
    vis[u][ a[u] ] = true;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v == fa) continue;
        dfs(v, u);
        memset(tmp, 0, sizeof(int)*m);
        for (int j = sz[u]-1; j >= 0; --j) {
            for (int k = 0; k < sz[v]; ++k) {
                int a = val[u][j], b = val[v][k];
                add(tmp[a^b], (ll)dp[u][a] * dp[v][b] % MOD);
                if (!vis[u][a^b]) val[u][sz[u]++] = a^b, vis[u][a^b] = true;
            }
        }
        for (int j = 0; j < m; ++j) add(dp[u][j], tmp[j]);
    }
}


void init() {
    memset(head, -1, sizeof(int)*(n+2));
    memset(sz, 0, sizeof(int)*(n+2));
    for (int i = 0; i <= n; ++i)
        memset(dp[i], 0, sizeof(int)*m), memset(vis[i], 0, sizeof(int)*m);
    cntE = 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int T = Scan();
    while (T--) {
        n = Scan(), m = Scan();
        init();
        for (int i = 1; i <= n; ++i) a[i] = Scan();
        for (int i = 1; i < n; ++i) addedge(Scan(), Scan());
        dfs(1, 0);

        for (int k = 0; k < m; ++k) {
            int ans = 0;
            for (int i = 1; i <= n; ++i) add(ans, dp[i][k]);
            printf("%d%c", ans, k==m-1?'\n':' ');
        }

    }
    return 0;
}