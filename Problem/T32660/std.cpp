#include <bits/stdc++.h>
using namespace std;

int arr[502], d[502];
int n, m, k, t, t2;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t); t2 = t;
		swap(arr[0], t2);
		for (int j = 1; j < i; j++) {
			arr[j-1] = t;
			t -= t2;
			t2 = arr[j];
			arr[j] = t;
		}
		d[i] = arr[i-1];
	}
	while (m--) {
		for (int j = n-1; j >= 0; j--) {
			arr[j] = (arr[j] + arr[j+1]) % 998244353;
		}
		printf("%d ", arr[0]);
	}
	return 0;
}

#if 0
3
1 4 9

6 5
864 1050 768 0 -960 -1386

0
5148
16800
38610

420 + 479j + 14j^2 - 48j^3 - 2j^4 + j^5

6 14
-16632 -5200 0 1584 1400 648

0 -280 -216 0 128 0 -360 -616 0 2808 9800 23760 48384 88400
#endif
