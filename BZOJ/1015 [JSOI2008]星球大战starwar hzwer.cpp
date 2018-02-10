#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tot,n,m,d,father[400001],head[400001],q[400001],ans[400001],cnt=1;
bool used[400001],des[400001];
struct data{int to,next;}e[400001];
int find(int x){return x==father[x]?x:father[x]=find(father[x]);}
void ins(int u,int v)
{
    cnt++;e[cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
    cnt++;e[cnt].to=u;e[cnt].next=head[v];head[v]=cnt;
}
void add(int x)
{
    int i=head[x],p=find(x),q;
    while(i)
    {
        if(used[e[i].to])
        {
            q=find(e[i].to);
            if(p!=q){father[q]=p;tot--;}
        }
        i=e[i].next;
    } 
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)father[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ins(x,y);
    }
    scanf("%d",&d);
    for(int i=1;i<=d;i++)
    {
        scanf("%d",&q[i]);
        des[q[i]]=1; 
    }
    for(int i=0;i<n;i++)
    {
        if(!des[i])
        {
            tot++;
            add(i);
            used[i]=1;
        }
    }
    ans[d+1]=tot;
    for(int i=d;i>0;i--)
    {
        tot++;
        add(q[i]);
        used[q[i]]=1;
        ans[i]=tot;
    }
    for(int i=1;i<=d+1;i++)printf("%d\n",ans[i]);
    return 0;
}
