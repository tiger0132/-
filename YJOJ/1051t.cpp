/*by SilverN*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int mxn=410;
int n,m;
vector<int>e[mxn];
int sc[mxn];
int f[mxn][mxn];//[课程序号][本层选课数] 
void add_edge(int u,int v){
    e[v].push_back(u);
    return;
}
void dp(int x){
    for(int i=1;i<=m;i++)f[x][i]=sc[x];
    for(int i=0;i<e[x].size();i++){
        int v=e[x][i];
        dp(v);
        for(int j=m;j;j--){//选j门课 
            for(int k=0;k<j;k++){
                f[x][j]=max(f[x][j],f[x][j-k]+f[v][k]);
            }
        }
    }
    return;
}
int main(){
    scanf("%d%d",&n,&m);
    int i,j;
    int s,k;
    for(i=1;i<=n;i++){
        scanf("%d%d",&k,&sc[i]);
        add_edge(i,k);
    }
    m++;//虚拟根节点占用一个位置 
    dp(0);
    printf("%d\n",f[0][m]);
    return 0;
}