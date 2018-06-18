#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;
#define CLR(x,y) memset((x),(y),sizeof((x)))
#define getint(x) int (x);scanf("%d",&(x))
#define get2int(x,y) int (x),(y);scanf("%d%d",&(x),&(y))
#define get3int(x,y,z) int (x),(y),(z);scanf("%d%d%d",&(x),&(y),&(z))
#define getll(x) LL (x);scanf("%I64d",&(x))
#define get2ll(x,y) LL (x),(y);scanf("%I64d%I64d",&(x),&(y))
#define get3ll(x,y,z) LL (x),(y),(z);scanf("%I64d%I64d%I64d",&(x),&(y),&(z))
#define getdb(x) double (x);scanf("%lf",&(x))
#define get2db(x,y) double (x),(y);scanf("%lf%lf",&(x),&(y))
#define get3db(x,y,z) double (x),(y),(z);scanf("%lf%lf%lf",&(x),&(y),&(z))
 
#define getint2(x) scanf("%d",&(x))
#define get2int2(x,y) scanf("%d%d",&(x),&(y))
#define get3int2(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define getll2(x) scanf("%I64d",&(x))
#define get2ll2(x,y) scanf("%I64d%I64d",&(x),&(y))
#define get3ll2(x,y,z) scanf("%I64d%I64d%I64d",&(x),&(y),&(z))
#define getdb2(x) scanf("%lf",&(x))
#define get2db2(x,y) scanf("%lf%lf",&(x),&(y))
#define get3db2(x,y,z) scanf("%lf%lf%lf",&(x),&(y),&(z))
 
#define getstr(str) scanf("%s",str)
#define get2str(str1,str2) scanf("%s",str1,str2)
#define FOR(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define FORD(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define FOR2(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define FORD2(x,y,z) for((x)=(y);(x)>=(z);(x)--)
 
const int maxn = 10000 + 100;
const int maxm = (50000 + 100)*2;
int head[maxn];//head[i]表示第i个顶点，第一个链节的编号
int next[maxm];//表示 第 q 号链节，下一个链节的编号
int end[maxm];//表示 第 q 个链节 的终点
int vis[maxm];//表示第q个链节是否被访问过.
void addedge(int from,int to){
		static int q = 1;
		end[q] = to;
		next[q] = head[from];
		head[from] = q++;
}
 
 
int n,m;
 
void dfs(int cur){
		for(int q = head[cur];q;q = next[q])
		{
				if(!vis[q])
				{
						vis[q] = 1;
						dfs(end[q]);
				}
		}
		printf("%d\n",cur);
}
 
int main()
{
		get2int2(n,m);
		int a,b;
		//CLR(next,0);CLR(end,0);CLR(head,0);CLR(vis,0);
		FOR(i,0,m){
				get2int2(a,b);
				addedge(a,b);
				addedge(b,a);
		}
		dfs(1);
		return 0;
}
