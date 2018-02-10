#include <bits/stdc++.h>
#define N 50005
typedef long long ll;
using namespace std;

struct query {
	int l, r, x;
	ll a, b;
} q[N];

int n, m, cnt, color[N], part[N];
ll sum[N], ans;

ll sqr(ll x) {
	return x*x;
} 
int cmp_ex(const query& a, const query& b) {
	return part[a.l] == part[b.l] ? a.r < b.r : a.l < b.l;
}
int cmp(const query& a, const query& b) {
	return a.x < b.x;
}
ll gcd(ll a, ll b) {
	while(b ^= a ^= b ^= a %= b);
	return a;
}
void mptr(int x, int ofs) {
	ans -= sqr(sum[color[x]]),
	sum[color[x]] += ofs,
	ans += sqr(sum[color[x]]);
}

int main() {
    scanf("%d%d",&n,&m);cnt=sqrt(n);
    go(i,1,n)scanf("%d",&col[i]),Be[i]=i/unit+1;;
    go(i,1,m)scanf("%d%d",&q[i].l,&q[i].r),q[i].ID=i;
    
    sort(q+1,q+m+1,cmp);
    
    int l=1,r=0;
    go(i,1,m)
    {
        while(l<q[i].l)revise(l,-1),l++;
        while(l>q[i].l)revise(l-1,1),l--;
        while(r<q[i].r)revise(r+1,1),r++;
        while(r>q[i].r)revise(r,-1),r--;
        
        if(q[i].l==q[i].r){
		q[i].A=0;q[i].B=1;continue;
		}
        q[i].A=ans-(q[i].r-q[i].l+1);
        q[i].B=1LL*(q[i].r-q[i].l+1)*(q[i].r-q[i].l);
        ll gcd=GCD(q[i].A,q[i].B);q[i].A/=gcd;q[i].B/=gcd;
    }
    
    sort(q+1,q+m+1,CMP);
    go(i,1,m)printf("%lld/%lld\n",q[i].A,q[i].B);
    return 0;
}
