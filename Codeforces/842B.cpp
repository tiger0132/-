#include <bits/stdc++.h>
using namespace std;

int r, d, n, x, y, z, c;
double dis;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cin >> r >> d >> n;
    while (n--) cin >> x >> y >> z, (dis = sqrt(x * x + y * y)), c += (dis - z >= r - d && dis + z <= r);
    cout << c;
}