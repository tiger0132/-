
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 5000+5;
char str[maxn*2];
int a[26][26][maxn];
int tot,n;

int main(){
    scanf("%s",str+1);
    n = strlen(str+1);
    for (int i=1; i<=n; i++) str[i+n] = str[i];
    memset(a,0,sizeof(a));
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<i+n; j++) a[str[i]-'a'][str[j]-'a'][j-i+1]++;

    tot = 0;
    for (int i=0; i<26; i++) {
        int tmp = 0;
        for (int j=1; j<=n; j++) {
            int sum = 0;
            for (int k=0; k<26; k++) if (a[i][k][j]==1) sum++;
            tmp = max(sum,tmp);
        }
        tot += tmp;
    }
    printf("%.14f\n",double(tot)/n);
    return 0;
}

