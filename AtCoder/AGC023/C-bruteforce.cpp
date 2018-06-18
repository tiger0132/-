#include <bits/stdc++.h>
using namespace std;

long long ans;
int arr[1003];
int n;

int calc() {
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		tmp |= 3 << arr[i];
		if (tmp == ((1 << n+1) - 1)) return i+1;
	}
}

int main() {
	n++;
	while (1) {
		n++;
		memset(arr, 0, sizeof arr);
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		ans = 0;
		do {
			// printf("%d\n", calc());
			ans += calc();
		} while (next_permutation(arr, arr+n));
		printf("%d: %d\n", n, ans);
	}
	return 0;
}