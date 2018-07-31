#include <bits/stdc++.h>
using namespace std;
int n,m;
set<int> s;
set<int>::iterator iter;
int dfsxv[100010],dfsxf[100010],hhd,vis[100010],cas;
struct edge{
	int to,net,cost;
	edge(int a = 0,int b = 0,int k = 0)
	{
		to = a;
		net = b;
		cost = k;
	}
};
int tot = 0,head[100010],p[100010][35],dis[100010],deep[100010];
edge edges[200010];
void add(int x, int y,int k)
{
	edges[++tot] = edge(y,head[x],k);
	head[x] = tot;
}
void dfs(int x,int fa)
{

	dfsxv[x] = ++hhd;	dfsxf[hhd] = x;
	for (int i = head[x]; i; i = edges[i].net)
	{
		edge& v = edges[i];
		if(v.to == fa) continue;
		p[v.to][0] = x;
		dis[v.to] = dis[x] + v.cost;
		deep[v.to] = deep[x] + 1;
		dfs(v.to,x);
	}
}
int lca(int x, int y)
{
	if(deep[x] < deep[y]) swap(x,y);
	int f = deep[x] - deep[y];
	for (int i = 0; (1 << i) <= f; i++)
	{
		if(f & (1 << i))
		{
			x = p[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 32; i >= 0; i--)
	{
		if(p[x][i] != p[y][i])
		{
			x = p[x][i];
			y = p[y][i];
		}
	}
	return p[x][0];
}
int solve(int x)
{
	int p,q;
	if(s.size() == 0)
	{
	//	printf("MDZZ %d\n",x);
		return 0;
	}
	iter = s.lower_bound(dfsxv[x]);
	if(iter == s.begin() || iter == s.end())
	{
		p = dfsxf[*s.begin()];
		q = dfsxf[*s.rbegin()];
	}else
	{
	
		p = dfsxf[*iter];
		iter--;
		q = dfsxf[*iter];
	}
//	printf("Pay Attention to : %d %d %d %d",dis[x],dis[lca(p,q)],dis[lca(x,p)],dis[lca(x,q)]);
	 return dis[x]+dis[lca(p,q)]-dis[lca(x,p)]-dis[lca(x,q)];  
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		
		tot = 0;
		for (int i = 1; i <= n; i++)
		    head[i] = 0;
	
		for (int i = 1; i < n; i++)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			add(x,y,k);
			add(y,x,k);
		}    
		deep[0] = -1;
		deep[1] = 1;
	    dis[1] = 0;
		hhd = 0;
		memset(p,0,sizeof(p));
		dfs(1,-1);
		for (int j = 1; j <= 32; j++)
		{
			for (int i = 1; i <= n; i++)
			{
			     p[i][j] = p[p[i][j-1]][j-1];	
			}
		}
		s.clear();
		memset(vis,0,sizeof(vis));
		cas++;
		printf("Case #%d:\n",cas);
		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int op,x;
			scanf("%d%d",&op,&x);
			if(op == 1)
			{
				if(vis[x] == 0)
				{
					vis[x] = 1;
			//		printf("THIS IS 1 %d\n",s.size());
					ans+=solve(x);
				//	printf("%d\n",solve(x));
			//	printf("ee%d\n",i);
					s.insert(dfsxv[x]);
				}
			}
			if(op == 2)
			{
				if(vis[x])
				{
					vis[x] = 0;
				    s.erase(dfsxv[x]);
			//	    printf("THIS IS 2 %d\n",s.size());
				    ans -= solve(x);
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}