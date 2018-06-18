#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N=105;
const int INF=9999999;

int map[N][N],dist[N][N];
int road[N][N],path[N];

int m,n,cnt,ans;

void Init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j]=INF;
            road[i][j]=0;
        }
    }
}

/**记录最小环的路径*/
void Record(int s,int t)
{
    if(road[s][t])
    {
        Record(s,road[s][t]);
        Record(road[s][t],t);
    }
    else path[cnt++]=t;
}

void Floyd()
{
    int i,j,k;
    ans=INF;
    for(k=1;k<=n;k++)
    {
        /**最小负环的判定*/
        for(i=1;i<k;i++)
        {
            for(j=i+1;j<k;j++)
            {
                if(ans>dist[i][j]+map[i][k]+map[k][j])
                {
                    ans=dist[i][j]+map[i][k]+map[k][j];
                    cnt=0;
                    path[cnt++]=i;
                    Record(i,j);
                    path[cnt++]=k;
                }
            }
        }
        /**正常floyd部分*/
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    road[i][j]=k;
                }
            }
        }
    }
}

int main()
{
    int i,j,u,v,w;
    while(cin>>n>>m)
    {
        Init();
        while(m--)
        {
            cin>>u>>v>>w;
            if(w<dist[u][v]) /**如果有重边，就取最小的权值*/
            {
                dist[u][v]=w;
                dist[v][u]=w;
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=dist[i][j];
        Floyd();
        if(ans==INF) puts("No solution.");
        else
        {
            cout<<path[0];
            for(int i=1;i<cnt;i++)
                cout<<" "<<path[i];
            cout<<endl;
        }
    }
    return 0;
}