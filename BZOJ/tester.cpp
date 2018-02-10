#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#define go(i,a,b) for(int i=a;i<=b;i++)
#define mem(a,b) memset(a,b,sizeof(a))

#define ll long long 
#define CMP cmp
#define cnt unit
#define revise mptr
#define GCD gcd
#define col color
#define A a
#define B b
#define ID x
#define Be part

using namespace std;const int N=50003;
struct Mo{int l,r,ID;ll A,B;}q[N];ll S(ll x){return x*x;}
ll GCD(ll a,ll b){while(b^=a^=b^=a%=b);return a;}
int n,m,col[N],unit,Be[N];ll sum[N],ans;
bool cmp_ex(Mo a,Mo b){return Be[a.l]==Be[b.l]?a.r<b.r:a.l<b.l;}
bool CMP(Mo a,Mo b){return a.ID<b.ID;};
void revise(int x,int add){ans-=S(sum[col[x]]),sum[col[x]]+=add,ans+=S(sum[col[x]]);}
int main() {
	scanf("%d%d", &n, &m);
	cnt = sqrt(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", color+i);
		part[i] = i / cnt + 1;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].x = i;
	}
	sort(q+1, q+m+1, cmp_ex);
	int l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		while (l < q[i].l) mptr(l, -1), l++;
		while (l > q[i].l) mptr(l-1, 1), l--;
		while (r < q[i].r) mptr(r+1, 1), r++;
		while (r > q[i].r) mptr(l, -1), r--;
		if (q[i].l == q[i].r) {
			q[i].a = 0;
			q[i].b = 1;
			continue;
		}
		q[i].a = ans - (q[i].r - q[i].l + 1);
		q[i].b = 1ll * (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
		ll t = gcd(q[i].a, q[i].b);
//		ll t = 1;
		q[i].a /= t;
		q[i].b /= t;
	}
	sort(q+1, q+m+1, cmp);
	for (int i = 1; i <= m; i++) {
		printf("%lld/%lld\n", q[i].a, q[i].b);
	}
}
