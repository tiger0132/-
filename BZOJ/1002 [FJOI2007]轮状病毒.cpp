#include <bits/stdc++.h>
using namespace std;

int arr[127][63] = {{0}, {1}};
int len[127] = {1, 1};
int n;

void calc(int x) {
	int carry = 0;
	len[x] = len[x-1];
	for (int i = 0; i < len[x]; i++) {
		arr[x][i] = 3 * arr[x-1][i] + carry + 2 * !i;
		carry = arr[x][i] / 10;
		arr[x][i] %= 10;
	}
	if (carry) arr[x][len[x]++] = carry;
	for (int i = 0; i < len[x-2]; i++) {
		arr[x][i] -= arr[x-2][i];
		if (arr[x][i] < 0) {
			arr[x][i] += 10;
			arr[x][i+1]--;
		}
	}
	if (!arr[x][len[x]-1]) {
		len[x]--;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		calc(i);
	}
	for (int i = len[n] - 1; i + 1; i--) {
		printf("%d", arr[n][i]);
	}
}
