#include <bits/stdc++.h>
#define N 10003
#define ll long long
using namespace std;
ll n,m,ans,sum;
void dg(ll m,ll s,ll n)
{
    if(m==0)
    {
        if(n>ans || (n==ans && s>sum))
        {
            ans=n;
            sum=s;
        }
        return;
    }
    ll a=floor(pow(m,1.0/3));
    dg(m-a*a*a,s+a*a*a,n+1);
    dg(3*a*a-3*a,s+(a-1)*(a-1)*(a-1),n+1);
}
int main()
{
    scanf("%lld",&m);
    dg(m,0,0);
    printf("%lld %lld",ans,sum);
}