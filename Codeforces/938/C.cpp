#include <bits/stdc++.h>
using namespace std;

int t;
long long k;

int divide(long long n, long long m) {
	int a1 = floor(1. * n / m);
	int a2 = ceil (1. * n / m);
	if (a1 * m >= n && a1 % 2 == 1) return a1;
	if (a2 * m >= n && a2 % 2 == 1) return a2;
	return -1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%I64d", &k);
		long long beg = (long long)sqrt(k); 
		for (long long offn = -1701; offn <= 1718; offn++) {
			long long n = beg + offn;
			if (n <= 0) continue;
			for (long long m_ = 1; n * n - m_ * m_ >= k; m_++) {
				if (n * n - m_ * m_ == k) {
					long long ans = divide(n, m_);
					if (ans == -1) continue;
					printf("%I64d %I64d\n", n, (ans + 1) / 2);
					goto end;
				}
			}
		}
		puts("-1");
		end:;
	}
}

n^2-m^2=k
n^2-(n+x)^2=k
n^2-(n^2+2nx+x^2)=k
-2nx-x^2=k
k+x^2+2nx=0