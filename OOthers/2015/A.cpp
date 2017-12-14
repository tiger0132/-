#include <bits/stdc++.h>
using namespace std;

int arr[32][32];
int n, x, y;

int main() {
    scanf("%d", &n);
    arr[x = 1][y = (n >> 1)] = 1;
    for (int i = 2; i <= n * n; i++) {
        x--; y--;
        if (arr[x][y] || (x > n && y > n )) { // ÕýÏÂ·½
            x += 2; y++;
        }
    }
}