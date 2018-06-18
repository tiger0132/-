#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007 

char s2[2500006],s[2500006];
int p[2500006];

int manacher() {
s[0]='$';
s[1]='#';
int len=2;
int l=strlen(s2);
for(int i=0; i<l; i++) {
s[len++]=s2[i];
s[len++]='#';
}
s[len]='@';
s[len+1]=0;
int mx=0,id;
for(int i=1; i<len; i++) {
if(mx>i) p[i]=min(p[2*id-i],mx-i);
else p[i]=1;
while(s[i+p[i]]==s[i-p[i]]) 
p[i]++;
if(i+p[i]>mx) {
mx=i+p[i];
id=i;
}
}
return len-1;
}
int c[4][2500006];
void modify(int k,int l,int r,int v)  {
if(l>r) 
return;
c[k][l]=(c[k][l]+v)%mod;  
c[k][r+1]=(c[k][r+1]-v+mod)%mod; 
}
int main() {
while(scanf("%s",s2)!=EOF) {
int len=manacher();
memset(c,0,sizeof(c));
for(int i=len; i>=1; i--) {
modify(0,i-p[i]+1,i,i);
modify(2,i-p[i]+1,i,1);
}
for(int i=1; i<=len; i++) {
modify(1,i,i+p[i]-1,i);
modify(3,i,i+p[i]-1,1);
}
for(int k=0; k<4; k++)
for(int i=1; i<=len; i++) 
c[k][i]=(c[k][i]+c[k][i-1])%mod;
int ans=0;
for(int i=2; i<len-1; i+=2) {
int a=i,b=i+2;
int lsum=(c[0][b]-(long long)c[2][b]*(b/2)%mod+mod)%mod;
int rsum=(c[1][a]-(long long)c[3][a]*(a/2)%mod+mod)%mod;
ans=(ans+(long long)lsum*rsum%mod)%mod;
}
printf("%d\n",ans);
}
return 0;
}