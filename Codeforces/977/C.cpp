#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int n, k;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr+i);
	}
	sort(arr+1, arr+n+1);
	arr[n+1] = 0x3f3f3f3f;
	if (k == 0 && arr[1] > 1) {
		puts("1");
	} else if (k != 0 && arr[k] < arr[k+1]) {
		printf("%d", arr[k]);
	} else puts("-1");
	return 0;
}