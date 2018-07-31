//By SiriusRen
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 555555
int n,m,t1,t2,v,ed=4000;
double l=0,r=500000,mid,base;
struct Node{double x,y;}army[66],tower[66];
struct Dinic{
    int first[4005],next[N],v[N],w[N],vis[N],tot;
    void init(){memset(first,-1,sizeof(first)),tot=0;}
    void add(int x,int y,int z){Add(x,y,z),Add(y,x,0);}
    void Add(int x,int y,int z){w[tot]=z,v[tot]=y,next[tot]=first[x],first[x]=tot++;}
    bool tell(){
        memset(vis,-1,sizeof(vis)),vis[0]=0;
        queue<int>q;q.push(0);
        while(!q.empty()){
            int t=q.front();q.pop();
            for(int i=first[t];~i;i=next[i])
                if(w[i]&&vis[v[i]]==-1)
                    vis[v[i]]=vis[t]+1,q.push(v[i]);
        }
        return vis[ed]!=-1;
    }
    int zeng(int x,int y){
        if(x==ed)return y;
        int r=0;
        for(int i=first[x];~i&&y>r;i=next[i])
            if(w[i]&&vis[v[i]]==vis[x]+1){
                int t=zeng(v[i],min(w[i],y-r));
                w[i]-=t,w[i^1]+=t,r+=t;
            }
        if(!r)vis[x]=-1;
        return r;
    }
    int flow(){
        int jy,ans=0;
        while(tell())while(jy=zeng(0,0x3ffffff))ans+=jy;
        return ans;
    }
}dinic;
double dis(Node a,Node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
    scanf("%d%d%d%d%d",&n,&m,&t1,&t2,&v);
    for(int i=1;i<=m;i++)scanf("%lf%lf",&army[i].x,&army[i].y);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&tower[i].x,&tower[i].y);
    while(r-l>1e-7){
        mid=(l+r)/2;
        dinic.init();
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
                dinic.add(0,i+j*60,1);
        for(int i=1;i<=n;i++){
            base=1.0*t1/60;
            for(int j=0;j<m;j++){
                for(int k=1;k<=m;k++)
                    if(base+dis(tower[i],army[k])/v<mid)
                        dinic.add(i+j*60,3800+k,1);
                base+=t2+1.0*t1/60;
            }
        }
        for(int i=1;i<=m;i++)dinic.add(3800+i,3900+i,1),dinic.add(3900+i,4000,1);
        if(dinic.flow()==m)r=mid;
        else l=mid;
    }
    printf("%.6f\n",mid);
	return 0;
}