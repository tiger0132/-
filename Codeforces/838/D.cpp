#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

#define INF 0x3f3f3f3f

#define digit(c) ((c) >= '0' && (c) <= '9')
#define upper(c) ((c) >= 'A' && (c) <= 'Z')
#define lower(c) ((c) >= 'a' && (c) <= 'z')
#define getchar() ((char)fgetc(stdin))
#define putchar(c) fputc((c), stdout)
#define fill_arr(a, b) memset(a, b, sizeof(a))
#define fill_inf(a) memset(a, 0x3f, sizeof(a))
#define fill_zero(a) memset(a, 0, sizeof(a))

#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)

#if __cplusplus < 201103L
#	define foreach(i, a) for (__typeof(begin(a)) i = begin(a); i != end(a); i++)
#	define iter(i, a) for (__typeof(begin(a)) i = begin(a); i != end(a); i++)
#else
#	define foreach(i, a) for (auto i : a)
#	define iter(i, a) for (auto i = begin(a); i != end(a); i++)
#endif

#define all(a) (begin(a)), (end(a))

template <bool exp> class IF {
	public: enum { value = false };
};

template <> class IF<true> {
	public: enum { value = true };
};

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	
}
