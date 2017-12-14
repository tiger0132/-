#include <bits/stdc++.h>
using namespace std;

multiset<int> m;
set<int> s;
int n, x;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        s.insert(x);
        m.insert(x);
    }
    if (s.size() == 2 && m.count(*s.begin()) == m.count(*++s.begin())) {
        printf("YES\n%d %d", *s.begin(), *++s.begin());
    } else {
        puts("NO");
    }
}