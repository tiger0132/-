#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); i++)
#define repd(i,a,b) for(int (i) = (a); (i) >= (b); i--)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define mp make_pair
#define pb push_back
#define countbits __builtin_popcount
using namespace std;
#define is_digit(c) ((c) >= '0' && (c) <= '9')
#define is_upper(c) ((c) >= 'A' && (c) <= 'Z')
#define is_lower(c) ((c) >= 'a' && (c) <= 'z')
#define readchar() ((char)fgetc(stdin))
#define printchar(c) fputc((c), stdout)
void readline(char *s) {int len=0;char c;for(c=readchar(); c!='\n'; s[len++]=c, c=readchar());s[len]=0;}
void readstr(char *s) {int len=0;char c;for(c=readchar(); c!=' '&&c!='\n'; s[len++]=c, c=readchar());s[len]=0;}
void printstr(const char *s) {int len=strlen(s);rep(i,0,len-1) printchar(s[i]);}
void to_lower(char *s, int L, int R) {rep(i,L,R) if (is_upper(s[i])) s[i]=s[i]-'A'+'a';}
void to_upper(char *s, int L, int R) {rep(i,L,R) if (is_lower(s[i])) s[i]=s[i]-'a'+'A';}
ll readll() {
	char c;ll ans=0, x=1;for (c=readchar(); !is_digit(c)&&c!='-'; c=readchar());
	if (c=='-') x=-1, c=readchar();for (; is_digit(c); ans=ans*10+c-'0', c=readchar());return ans*x;
}
void printll(ll x) {
	int a[25], cnt=0;if (x==0) { printchar('0'); return; }if (x<0) printchar('-'), x=-x;
	for (; x; a[cnt++]=x-x/10*10, x/=10);repd(i,cnt-1,0) printchar(a[i]+'0');
}
#define readint() ((int)readll())
#define printint(x) printll((ll)(x))
char grid[105][105],s[105][105];
char str[]="-BGR";
int n,m;
int main() {
	n=readint();m=readint();
	rep(i,1,n) readstr(grid[i]+1);
	if (n%3==0) {
		do {
			rep(i,1,3) {
				rep(j,n/3*(i-1)+1,n/3*i)
					rep(k,1,m) s[j][k]=str[i];
			}
			bool f=true;
			rep(i,1,n) {
				rep(j,1,m) {
					if (grid[i][j]!=s[i][j]) {
						f=false;break;
					}
				}
			}
			if (f) {
				printstr("YES\n");
				return 0;
			}
		} while (next_permutation(str+1,str+4));
	}
	if (m%3==0) {
		sort(str+1,str+4);
		do {
			rep(i,1,3) {
				rep(j,m/3*(i-1)+1,m/3*i)
					rep(k,1,n) s[k][j]=str[i];
			}
			bool f=true;
			rep(i,1,n) {
				rep(j,1,m) {
					if (grid[i][j]!=s[i][j]) {
						f=false;break;
					}
				}
			}
			if (f) {
				printstr("YES\n");
				return 0;
			}
		} while (next_permutation(str+1,str+4));
	}
	printstr("NO\n");
	return 0;
}
