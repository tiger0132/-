#include <bits/stdc++.h>
using namespace std;

set<char> k;
string s;
int n;

int main() {
    cin >> n >> s;
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            sol = max(sol, (int)k.size());
            k.clear();
        } else {
            k.insert(s[i]);
        }
    }
    cout << max(sol, (int)k.size());
    return 0;
}