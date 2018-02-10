#include <bits/stdc++.h>
using namespace std;

int arr[1024];
int n;

int main() {
	while (~scanf("%d", arr+n++));
	sort(arr, arr+n-1);
	for (int i = 0; i < n-1; i++) {
		printf("%d ", arr[i]);
	}
}
