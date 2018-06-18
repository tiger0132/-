/*
           代码2
ps：这个代码不需要O2优化也能过(优化spfa的做法）
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,flag;//flag判断是否有负环
struct EE{
    int ne,to,z;
}e[1000000];
int js,h[200000];
void hh(int u,int v,int c)
{
    e[++js].ne=h[u];
    e[js].to=v;
    e[js].z=c;
    h[u]=js;
}
int bj[200000],zzt[200000],bs[200000];//和之前一样
void spfa(int k)
{
    bj[k]=0;//k出队
    for(int i=h[k];i;i=e[i].ne)
    {
        int o=e[i].to;//找k连接的点
        if(zzt[o]>zzt[k]+e[i].z)
        {
            zzt[o]=zzt[k]+e[i].z;
            bs[o]=bs[k]+1;//和之前的一样，不多说了
            if(bs[o]>n)
            {
                flag=1;
                return ;
            }
            if(bj[o]==0)
            {
                bj[o]=1;
                spfa(o);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        hh(0,i,0);
    for(int i=1;i<=m;i++)
    {
        int p,a,b,c;
        cin>>p;
        if(p==1)
        {
            cin>>a>>b>>c;
            hh(a,b,-c);
        }
        else if(p==2)
        {
            cin>>a>>b>>c;
            hh(b,a,c);
        }
        else
        {
            cin>>a>>b;
            hh(a,b,0);
            hh(b,a,0);
        }
    }
    memset(zzt,127,sizeof(zzt));//找最小值，赋值为最大
    zzt[0]=0;//本身到本身距离为零
    bj[0]=1;//标记
    spfa(0);//从零开始找
    if(flag)//有负环
        cout<<"No";
    else//无负环
        cout<<"Yes";
	return 0;
}