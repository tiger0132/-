#include <bits/stdc++.h>
using namespace std;

vector<int> equ[2000005];
int rec[100005], n, a;
char ch;

int main() {
    scanf("%*d"); getchar();
    while ((ch = getchar()) != '\n') {
        rec[n] = rec[n - 1];
        if (ch == 48) rec[n]--;
        else rec[n]++;
        n++;
    }
    equ[n].push_back(-1);
    for (int i = 0; i < n; i++) {
        equ[rec[i] + n].push_back(i);
    }
    for (int i = 0; i <= 2 * n; i++) {
        if (equ[i].size() < 2) continue;
        a = max(a, equ[i].back() - equ[i].front());
    }
    printf("%d", a);
}