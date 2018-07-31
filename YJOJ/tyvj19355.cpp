// Network Flow Template by tiger0132

#include <bits/stdc++.h>
using namespace std;
#define N 555555
int ed=4000;

struct Dinic{
    int first[4005],next[N],v[N],w[N],vis[N],tot;
    void init(){memset(first,-1,sizeof(first)),tot=0;}
    void add(int x,int y,int z){Add(x,y,z),Add(y,x,0);}
    void Add(int x,int y,int z){w[tot]=z,v[tot]=y,next[tot]=first[x],first[x]=tot++;}
    bool tell(){
        memset(vis,-1,sizeof(vis)),vis[4001]=0;
        queue<int>q;q.push(4001);
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
        while(tell())while(jy=zeng(4001,0x3ffffff))ans+=jy;
        return ans;
    }
}dinic;

/* ————————————SPLIT LINE ———————————— */ 

const double eps = 1e-7;

struct xy {
	double x, y;
} enemy[102], missle[102];

double l, r, st, v, mid;
int n, m, t1, t2, x, y;
double dis[102][102];

double dist(double X1, double Y1, double X2, double Y2) {
	return sqrt((X1-X2) * (X1-X2) + (Y1-Y2) * (Y1-Y2));
}

int main() {
	scanf("%d%d%d%d%lf", &n, &m, &t1, &t2, &v);
	for (int i = 1; i <= m; i++) {
		scanf("%lf%lf", &enemy[i].x, &enemy[i].y);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &missle[i].x, &missle[i].y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dis[i][j] = dist(missle[i].x, missle[i].y, enemy[j].x, enemy[j].y);
		}
	}
	r = 500000;
	while (r - l > eps) {
		dinic.init();
		mid = (l + r) / 2;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				dinic.add(4001, j*60 + i, 1);
			}
		}
		for (int i = 1; i <= n; i++) {
			// st = t1 / 60.;
			for (int j = 0; j < m; j++) {
				st = t1 * (j+1) / 60. + t2 * j;
				for (int k = 1; k <= m; k++) {
					if (st + dis[i][k] / v < mid) {
						dinic.add(j*60 + i, 3900 + k, 1);
					}
				}
				// st += t1 / 60. + t2;
			}
		}
		for (int i = 1; i <= m; i++) {
			dinic.add(3900 + i, 4000, 1);
		}
		if (dinic.flow() == m) r = mid;
		else l = mid;
	}
	printf("%.6f\n", mid);
	return 0;
}