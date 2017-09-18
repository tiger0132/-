// Readable Usable Compilable Scalable Expandable Defendable
// Super Hyper Ultra Extremely
// Good(Bad) Template
// By tiger0133

#include <ext/pb_ds/priority_queue.hpp>
#include <bits/stdc++.h>
using namespace std;

// ！！！！！！！！！！！！！！！！！！！！！    Constant    ！！！！！！！！！！！！！！！！！！！！！ //

#define N 1000005
#define MOD 1000000007

#define CINF 0x3f
#define CMAX 0x7f
#define UCMAX 0xff
#define SINF 0x3f3f
#define SMAX 0x7fff
#define USMAX 0xffff
#define IINF 0x3f3f3f3f
#define IMAX 0x7fffffff
#define UMAX 0xffffffff
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LLMAX 0x7fffffffffffffff
#define ULLMAX 0xffffffffffffffff

// ！！！！！！！！！！！    Function-Like Macro & Alias   ！！！！！！！！！！！！！ //

#define pue(c) while (!c.empty()) //pop until empty

#define clr(arr) memset(arr, 0, sizeof(arr));
#define inf(arr) memset(arr, CINF, sizeof(arr));

#define nln putchar('\n');
#define alm putchar('\a');
#define tab putchar('\t');
#define ret putchar('\r');
#define spc putchar(' ');

// ！！！！！！！！！！！！！！！！！！！！    Optimizes    ！！！！！！！！！！！！！！！！！！！！！ //

#define getchar getchar_x

// ！！！！！！！！！！！！！！！！！！！    Shorten Name    ！！！！！！！！！！！！！！！！！！！ //

typedef float fl;
typedef double db;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pir pair
#define vct vector
#define ary array
#define tup tuple
#define sta stack
#define deq deque
#define que queue
#define bst bitset
#define mst multiset
#define mmp multimap
#define ust unordered_set
#define ump unordered_map
#define pri priority_queue

#define pb emplace_back
#define pf emplace_front
#define psh emplace
#define itr iterator
#define rit reverse_iterator

#define st first
#define nd second

typedef pir<int, int> pii;
typedef tup<int, int, int> t3;

typedef vct<int> vi;
typedef vct<pii> vii;
typedef vct<t3> vt3;
typedef vct<vi> vvi;

typedef vi grh[N];
typedef vii wgr[N];

#define ppc __builtin_popcount
#define ffs __builtin_ffs
#define clz __builtin_clz
#define ctz __builtin_ctz
#define prt __builtin_parity

#define ppcl __builtin_popcountll
#define ffsl __builtin_ffsll
#define clzl __builtin_clzll
#define ctzl __builtin_ctzll
#define prtl __builtin_parityll

template <typename T = int>
using ar = T[N];

template <typename T = int>
using __pq = __gnu_pbds::priority_queue<T>;

// ！！！！！！！！！！！！！！！！！！！！！！！    Exit    ！！！！！！！！！！！！！！！！！！！！！！！ //

#ifdef __TIGER0133__

void pause() {
    double __used_time__ = clock() * 1. / CLOCKS_PER_SEC;
    cout.precision(3);
    cout << endl;
    cout << "--------------------------------" << endl;
    cout << "Process exited after "  << fixed << __used_time__ << " seconds with return value 0" << endl;
    cout << "Press any key to do nothing. . ." << endl;
    while (1);
}

void sigsegv(int code) {
    cout << "Program received signal SIGSEGV, Segmentation fault.";
    while (1);
}

#endif

// ！！！！！！！！！！！！！！！！！！！！！    Function    ！！！！！！！！！！！！！！！！！！！！！ //

inline void mat(int n, int m, int **arr) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

inline void mat(vvi& arr) {
    for (vi& i : arr) {
        for (int& j : i) {
            cin >> j;
        }
    }
}

char B[1 << 15], *S = B, *T = B;
inline char getcharx() { //泌惚方象嶄嗤掲方忖議補秘, 萩齢聞喘!
    return S == T && (T = (S = B) + fread(B, 1, 1 << 15, stdin), S == T) ? 0 : *S++;
}

template <typename T>
inline void get(register T& val) {
    register int fac = 1;
    register char ch;
    val = 0;
    while (!isdigit(ch = getcharx())) ch == 45 && (fac = -1);
    do {val = val * 10 + ch - 48;} while (isdigit(ch = getcharx()));
    val *= fac;
}

template <typename T>
inline bool put(register T val) {
    val < 0 && (val = -val);
    val > 9 && put(val / 10);
    putchar(val % 10 + 48);
    return true;
}

template <typename T, typename Compare = less<T>>
inline void normalize(T& x, const T& y, const Compare& comp = less<T>()) {
    if (!comp(x, y)) {
        x = y;
    }
}

// ！！！！！！！！！！！！！！！！！！！！！    Solution    ！！！！！！！！！！！！！！！！！！！！！ //

ar<bool> flg;

void proc() {
    vi v, r, o;
    int n, x;
    get(n);
    clr(flg);
    for (int i = 0; i < n; i++) {
        get(x);
        v.pb(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            flg[v[j] - v[i]] = true;
        }
    }
    for (int i = 1; i <= 10000000; i++) {
        bool con = !flg[i];
        for (int j : r) {
            if (!con) break;
            con &= !flg[i - j];
        }
        if (con) {
            r.pb(i); o.pb(i);
        }
        if (r.size() == n) {
            cout << "YES"; nln;
            for (int i : r) {
                put(i); spc;
            }
            nln; return;
        }
    }
    cout << "NO"; nln;
}

int main() {
    #ifdef __TIGER0133__
    signal(SIGSEGV, sigsegv);
    atexit(pause);
    #endif
    int t;
    for (get(t); t--; ) {
        proc();
    }
} 