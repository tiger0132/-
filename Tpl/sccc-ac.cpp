#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct shittt
{
    int aa;
    int bb;
}x1[1000001];
vector<int>a[100001],s[100001];//vector存边数组
queue<int>rt;//拓扑排序队列
bool v[100001],f[100001];//tanjan用的标记数组
int stack[100001],h,u,cnt,low[100001],dfn[100001],number[100001],b[100001];
//number表示连通块大小，b记录每个点所在的连通块，low和dfn是tanjan用的数组，stack是tarjan用的栈。
int sum[100001],dp[100001],r[100001];//sum表示最长链大小，dp表示个数，r存储连通块的入度
void dfs(int o)//tanjan缩点。
{
    u++;
    low[o]=dfn[o]=u;
    h++;
    stack[h]=o;
    f[o]=true;
    if(!a[o].empty())
        for(int i=0;i<a[o].size();i++)
            if(!v[a[o][i]])
            {
                v[a[o][i]]=true;
                dfs(a[o][i]);
                low[o]=min(low[o],low[a[o][i]]);
            }else if(f[a[o][i]]) low[o]=min(low[o],dfn[a[o][i]]);
    if(low[o]==dfn[o])//找到一个连通块
    {
        cnt++;//新的标号
        while(stack[h]!=o)
        {
            b[stack[h]]=cnt;
            number[cnt]++;//连通块大小++
            f[stack[h]]=false;
            h--;//出栈
        }
        b[stack[h]]=cnt;
        number[cnt]++;
        f[stack[h]]=false;
        h--;
    }
}
bool cmp(shittt a1,shittt b1)//排序条件函数
{
    return((a1.aa<b1.aa)||((a1.aa==b1.aa)&&(a1.bb<b1.bb)));
}
int main()
{
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=1;i<=m;i++)
    {
        int xx,yy;
        cin>>xx>>yy;
        a[xx].push_back(yy);//用vector存边
    }
    memset(v,0,sizeof(v));
    memset(f,0,sizeof(f));
    u=cnt=0;
    for(int i=1;i<=n;i++)
        if(!v[i])//可能原图不是连通的，会有多个块组成。
        {
            v[i]=true;
            dfs(i);
        }
    int re=0;
    for(int i=1;i<=n;i++)
        if(!a[i].empty())
            for(int j=0;j<a[i].size();j++)
                if(b[i]!=b[a[i][j]])
                {
                    x1[++re].aa=b[i];
                    x1[re].bb=b[a[i][j]];
}//记录新的边（缩点之后连通块之间的边）

    sort(x1+1,x1+re,cmp);//排序去除重边。
    memset(r,0,sizeof(r));
    for(int i=1;i<=re;i++)
    {
        if((x1[i].aa==x1[i-1].aa)&&(x1[i].bb==x1[i-1].bb)) continue;
        s[x1[i].aa].push_back(x1[i].bb);
        r[x1[i].bb]++;
    }
    for(int i=1;i<=cnt;i++)//DP初始化
        if(r[i]==0) 
        {
            rt.push(i);
            sum[i]=number[i];
            dp[i]=1;
        }
    while(!rt.empty())//拓扑排序（用队列存入度为零的点）+DP
    {
        int yu=rt.front();
        rt.pop();
        for(int i=0;i<s[yu].size();i++)
        {
            r[s[yu][i]]--;
            if(r[s[yu][i]]==0)
                rt.push(s[yu][i]);
            if(sum[yu]+number[s[yu][i]]==sum[s[yu][i]]) //转移状态
            {
                dp[s[yu][i]]+=dp[yu];
                dp[s[yu][i]]%=x;
            }else
            if(sum[yu]+number[s[yu][i]]>sum[s[yu][i]])
            {
                dp[s[yu][i]]=dp[yu];
                sum[s[yu][i]]=sum[yu]+number[s[yu][i]];
            }
        }
    }
    int yu=0,k=0;
    for(int i=1;i<=cnt;i++)
        if(sum[i]>sum[yu]){yu=i;k=dp[i];}
            else if(sum[i]==sum[yu]){k+=dp[i];k%=x;}//求出最终值
    cout<<sum[yu]<<endl<<k<<endl;
    return 0;
}