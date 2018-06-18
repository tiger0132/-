#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 510;
int uN,vN;//u,v的数目，使用前面必须赋值
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN],pipei;
bool used[MAXN],stu[MAXN],hom[MAXN];
bool dfs(int u)
{
    for(int v = 1; v <=vN;v++)
        if(stu[v] && g[u][v] && !used[v])//这里匹配就要匹配是在校学生的 因为不是在校学生的话没有床 
        {
            used[v] = true;
            if(linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
bool hungary()//匈牙利算法 
{
    int res = 0;
    memset(linker,-1,sizeof(linker));
    for(int u = 1;u <= uN;u++)
    {
        memset(used,false,sizeof(used));
        if((!stu[u] ||!hom[u]) && !dfs(u))    return 0;// 给每个不是在校学生或者不回家的匹配  如果不成功就返回 
    }
    return 1;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        uN=vN=n;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
            scanf("%d",&stu[i]);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&hom[i]);
            if(!stu[i])
                hom[i]=1;    //如果不是在校学生就默认回家了 
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%d",&g[i][j]);
            if(stu[i])g[i][i]=1;//匹配自己的床 
        }
        printf("%s\n",hungary()?"^_^":"T_T");
    }
    return 0;
}