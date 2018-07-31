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

poly a=x^2+2*x+1;
poly b=~(x^3+4*x^2+2*x+1).integral();
cout << a*ln(b);