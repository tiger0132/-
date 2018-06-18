#include<iostream>
#include<cstdio>
#define N 10
using namespace std;
int n,k,cnt,q[N],head[N],cir[N],dis[N];
long long ans;
bool inq[N];
struct data{int to,next,v;}e[4*N];
void insert(int u,int v,int w){e[++cnt].to=v;e[cnt].next=head[u];e[cnt].v=w;head[u]=cnt;}
bool spfa()
{
     int t=0,w=1,now;
     q[0]=0;inq[0]=1;cir[0]=1;
     while(t!=w)
     {
               now=q[t];t++;if(t==N)t=0;
               for(int i=head[now];i;i=e[i].next)
               {
                       if(dis[now]+e[i].v>dis[e[i].to])
                       {
                           dis[e[i].to]=dis[now]+e[i].v;
                           if(++cir[e[i].to]>=n)return 0;
                           if(!inq[e[i].to])
                           {
                               inq[e[i].to]=1;q[w++]=e[i].to;
                               if(w==N)w=0;
                           }
                       }
               }
     inq[now]=0;
     }
     return 1;
 }
int main()
{
    scanf("%d%d",&n,&k);int x,a,b;
    while(k--)
    {
       scanf("%d%d%d",&x,&a,&b);
       switch(x)
       {
                case 1:insert(a,b,0);insert(b,a,0);break;
                case 2:if(a==b){printf("-1");return 0;}
                     insert(a,b,1);break;
                case 3:insert(b,a,0);break;
                case 4:if(a==b){printf("-1");return 0;}
                     insert(b,a,1);break;
                case 5:insert(a,b,0);break;
                }
       }
    for(int i=n;i>0;i--)insert(0,i,1);
    if(!spfa()){printf("-1");return 0;}
    for(int i=1;i<=n;i++)ans+=dis[i];
    printf("%lld",ans);
    return 0;
}