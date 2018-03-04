#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, x;
    cin >> T;
    while (T--) {
        cin >> x;
        if (x == 0) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        long long res1 = 0, res2 = 0;
        for (long long i = 1; i * i <= x; i++) {    // n - n / m
            if (x % i == 0) {
                long long j = x / i;                // n + n / m
                long long n = (i + j) >> 1;
                if (n <= i) continue;
                long long m = n / (n - i);
                if (n >= 1 && m >= 1 && n >= m && (n - n / m) * (n + n / m) == x) {
                    res1 = n, res2 = m;
                }
            }
        }
        if (!res1) {
            cout << -1 << endl;
        } else {
            cout << res1 << " " << res2 << endl;
        }
    }
    return 0;
}

#if 0
36514 2
36513 2
31622 97
36511 2
31642 26
36509 2
36508 2
36507 2
36506 2
36505 2
31941 7
36503 2
36502 2
36501 2
36500 2
36499 2
36498 2
31631 26
31934 7
36495 2
36494 2
36493 2
36492 2
36491 2
36490 2
36489 2
31927 7
36487 2
36486 2
36485 2
36484 2
36483 2
36482 2
36481 2
31616 26
36479 2
36478 2
36477 2
36476 2
36475 2
36474 2
36473 2
31913 7
36471 2
36470 2
36469 2
36468 2
31605 26
36466 2
36465 2
31906 7
36463 2
36462 2
100 33
66 7
17 2
35 17
#endif