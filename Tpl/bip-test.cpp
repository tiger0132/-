#include<cstdio>
#include<cstring>
using namespace std;

const int N = 1e3;
bool f[N][N];
bool used[N];
int match[N];
int n,m,e;

bool DFS(int pos)
{
    for(int i=1; i<=m; i++)
    {
        if(f[pos][i] && !used[i])
        {
            used[i] = true;
            if(!match[i] || DFS(match[i])) //如果这个点i还未匹配则pos和他匹配，如果这个点已经匹配，那么如果本来和他匹配的点match[i]还能找到另一个点匹配则pos把i“抢”过来，让match[i]去匹配另一个点，否则就不干涉i和match[i]匹配
            {
                match[i] = pos;
                return true;
            }
        }
    }
    return false; 
}

int main()
{
	freopen("C:\\Users\\Administrator\\Documents\\testdata (6).in", "r", stdin);
    scanf("%d%d%d",&n,&m,&e);
    for(int i=1; i<=e; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        if(x<=n && y<=m) f[x][y] = true; 
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        memset(used,false,sizeof(used)); //注意此处
        if(DFS(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}