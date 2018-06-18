#include <bits/stdc++.h>
using namespace std;

int match[102],matched;
int gph[102][102];
bool used[102],stu[102],hom[102];
bool dfs(int u)
{
	for(int v = 1; v <=n;v++) {
		if(stu[v] && gph[u][v] && !used[v])//这里匹配就要匹配是在校学生的 因为不是在校学生的话没有床 
		{
			used[v] = true;
			if(match[v] == -1 || dfs(match[v]))
			{
				match[v] = u;
				return true;
			}
		}
	return false;
}

bool hungary() {
	int res = 0;
	memset(match,-1,sizeof(match));
	for (int u = 1;u <= n;u++) {
		memset(used,false,sizeof(used));
		if((!stu[u] || !hom[u]) && !dfs(u)) return 0;
	}
	return 1;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d", &n);
		memset(gph,0,sizeof(gph));
		for(int i=1;i<=n;i++)
			scanf("%d",&stu[i]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&hom[i]);
			if(!stu[i])
				hom[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				scanf("%d",&gph[i][j]);
			if(stu[i])gph[i][i]=1;
		}
		printf("%s\n",hungary()?"^_^":"T_T");
	}
	return 0;
}