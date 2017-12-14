#include <bits/stdc++.h>
using namespace std;

int rec[100005];
int cnt[100005];
int skp[100005];
queue<int> nev;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &rec[i]);
        cnt[rec[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!rec[i]) nev.push(i);
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[rec[i]] > 1) {
            if (nev.top() < rec[i] || skp[i]) {
                
            } else {

            }
        }
    }
    while (1);
    return 0;
}